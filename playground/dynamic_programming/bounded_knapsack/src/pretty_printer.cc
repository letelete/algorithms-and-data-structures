#include "../include/pretty_printer.hh"

#include <functional>
#include <iomanip>

void PrettyPrinter::print_items_horizontally(const std::vector<Item*>& items) {
  if (items.empty()) return;

  int right_border_width = 1;
  int column_width = _fixed_column_width(items);
  int output_width = (items.size() * column_width) + right_border_width;

  auto print_vertical_border = [&output_width]() {
    for (int i = 0; i < output_width; ++i) std::cout << _border_indicator;
    std::cout << '\n';
  };

  auto print_item_tag = [&column_width](
                            const std::vector<Item*>& items,
                            std::function<std::string(Item*)> const& item_tag) {
    std::cout << _border_indicator;
    for (unsigned i = 0; i < items.size(); ++i) {
      std::cout << std::setw(column_width - _item_horizontal_margin)
                << item_tag(items[i]) << std::setw(_item_horizontal_margin)
                << _border_indicator;
    }
    std::cout << "\n";
  };

  print_vertical_border();
  print_item_tag(items, [&](Item* item) { return item->name_tag(); });
  print_item_tag(items, [&](Item* item) { return item->cost_tag(); });
  print_item_tag(items, [&](Item* item) { return item->weight_tag(); });
  print_item_tag(items, [&](Item* item) { return item->quantity_tag(); });
  print_vertical_border();
}

/**
 * Returns a width parameter of each column in the stream of items
 * example with width = 3:
 * - [  a][ ab][abc][  x]
 */
int PrettyPrinter::_fixed_column_width(const std::vector<Item*>& items) {
  if (items.empty()) return 0;

  int margin_space = 2 * _item_horizontal_margin;
  int width = 0;

  for (const auto& item : items) {
    int item_name_length = item->name.length() + margin_space;
    width = std::max(width, item_name_length);
  }

  return width;
}
