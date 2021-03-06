from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as ec
from selenium.webdriver.common.by import By
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.chrome.options import Options


class Task:
    def __init__(self, url, number, name, diff):
        self.__separator = "_"
        self.url = self.__format_url(url)
        self.number = self.__format_number(number)
        self.name = self.__format_name(name)
        self.diff = self.__format_diff(diff)

    # template: 001_abc_[hard].cpp
    def get_filename(self):
        return "{}{}{}{}{}.cpp".format(
            self.number, self.__separator, self.name, self.__separator, self.diff
        )

    def __format_url(self, url):
        last_character_index = len(url) - 1
        if url[last_character_index] == "/":
            return url[0:last_character_index]
        return url

    # template: 001, 010, 100
    def __format_number(self, number):
        number_length = 3
        formatted = str(number)
        while len(formatted) < number_length:
            formatted = "0" + formatted
        return formatted

    # template: abc_abc_abc
    def __format_name(self, name):
        name = name.lower()
        name_words = name.split(" ")
        formatted = name_words[0]
        print(formatted)
        for index in range(1, len(name_words)):
            formatted += self.__separator + name_words[index]
        return formatted

    # template: [hard]
    def __format_diff(self, diff):
        return "[{}]".format(diff.lower())


class Scrapper:
    def __init__(self, url):
        self.url = url
        self.success = True

    def fetch_page(self):
        # template: Hard
        task_diff_xpath = (
            "//div[@diff='easy'] | //div[@diff='medium'] | //div[@diff='hard']"
        )
        # template: 4. Bla bla bla
        task_fullname_xpath = "//div[@data-cy='question-title']"
        driver = self.__get_driver()
        try:
            wait = WebDriverWait(driver, 10)
            name = wait.until(
                ec.visibility_of_element_located((By.XPATH, task_fullname_xpath))
            )
            diff = wait.until(
                ec.visibility_of_element_located((By.XPATH, task_diff_xpath))
            )
            self.raw_name = name.text
            self.raw_diff = diff.text
        except TimeoutException as e:
            message = "Couldn't scrap elements from given url '{}'".format(self.url)
            if e.__class__ == TimeoutException:
                message = "Loading page took too much time"
            print(message, e)
            self.success = False
        finally:
            driver.close()

    def __get_driver(self):
        options = Options()
        options.add_argument("--headless")
        driver = webdriver.Chrome(options=options)
        driver.get(self.url)
        return driver

    def get_task(self):
        number_and_name = self.raw_name.split(". ", 1)
        if len(number_and_name) != 2:
            print("Number and name fields weren't splitted properly")
            return None

        number = number_and_name[0]
        name = number_and_name[1]
        diff = self.raw_diff

        return Task(self.url, number, name, diff)


class AddTask:
    def __init__(self, task_url):
        self.__solutions_dirname = "solutions"
        self.task = None
        scrapper = Scrapper(task_url)

        scrapper.fetch_page()
        if scrapper.success:
            self.task = scrapper.get_task()

    # Inserts properly formatted task into readme and marks it as solved.
    # The insertion index equals to the latest solved task index + 1.
    # All solved tasks should move at the top of the file.
    def into_readme(self):
        solved_task_readme_line = self.__beginning_of_task_readme_line(solved=True)
        new_task_readme_line = self.__beginning_of_task_readme_line(
            solved=False, name=self.task.name
        )

        path = self.__readme_relative_filepath()

        file = open(path, "r+")
        content = file.readlines()
        file.seek(0)
        file.truncate(0)

        last_solved_task_index = 0
        readme_contains_task = False

        for index, line in enumerate(content):
            if solved_task_readme_line in line:
                last_solved_task_index = index
                file.write(line)
            elif last_solved_task_index == 0:
                file.write(line)
            if new_task_readme_line in line:
                readme_contains_task = True
                content.pop(index)
                break

        if not readme_contains_task:
            print(
                "Task '{}' not found in the readme file.".format(self.task.name),
                "Appending as a new one.",
            )

        file.write(self.__get_task_readme_line())

        for line in content[last_solved_task_index + 1 :]:
            file.write(line)

        file.close()

    def __beginning_of_task_readme_line(self, solved=True, name=""):
        checkbox = "x" if solved else " "
        return "- [{}] {}".format(checkbox, name)

    # template: - [ ] container-with-most-water [Description](https://leetcode.com/problems/container-with-most-water)
    # after insertion: - [x] container-with-most-water [Solution](filepath) | [Description](https://leetcode.com/problems/container-with-most-water)
    def __get_task_readme_line(self):
        check = "- [x]"
        solution_path = "{}/{}".format(
            self.__solutions_dirname, self.task.get_filename()
        )
        description_path = self.task.url
        name = self.task.name
        new_line = "{} {} [Solution]({}) | [Description]({})\n".format(
            check, name, solution_path, description_path
        )
        return new_line

    def into_solutions_as_file(self):
        path = self.__task_relative_filepath()
        file = open(path, "w+")
        file.close()

    def __readme_relative_filepath(self):
        filename = "readme.md"
        path = "../" + filename
        return path

    def __task_relative_filepath(self):
        task_filename = self.task.get_filename()
        all_tasks_filepath = "../{}".format(self.__solutions_dirname)
        path = all_tasks_filepath + "/" + task_filename
        return path


print("Insert a leetcode task url")
add_task = AddTask(input())
if add_task.task != None:
    add_task.into_readme()
    add_task.into_solutions_as_file()
    print("Done! Happy coding :)")
else:
    print("Couldn't add a new task")

