#include "go_to.h"

namespace lsp_handlers {
std::optional<json> go_to_definition(Workspace& workspace, int /*id*/, json raw_params) {
  auto params = raw_params.get<LSPSpec::TextDocumentPositionParams>();
  const auto file_type = workspace.determine_filetype_from_uri(params.m_textDocument.m_uri);

  json locations = json::array();

  if (file_type == Workspace::FileType::OpenGOALIR) {
    auto maybe_tracked_file = workspace.get_tracked_ir_file(params.m_textDocument.m_uri);
    if (!maybe_tracked_file) {
      return {};
    }
    const auto& tracked_file = maybe_tracked_file.value().get();
    auto symbol_name = tracked_file.get_symbol_at_position(params.m_position);
    if (!symbol_name) {
      return {};
    }
    auto symbol_info = workspace.get_definition_info_from_all_types(symbol_name.value(),
                                                                    tracked_file.m_all_types_uri);
    if (!symbol_info) {
      return {};
    }
    LSPSpec::Location location;
    location.m_uri = tracked_file.m_all_types_uri;
    location.m_range.m_start = {(uint32_t)symbol_info.value().definition_info->line_idx_to_display,
                                (uint32_t)symbol_info.value().definition_info->pos_in_line};
    location.m_range.m_end = {(uint32_t)symbol_info.value().definition_info->line_idx_to_display,
                              (uint32_t)symbol_info.value().definition_info->pos_in_line};
    locations.push_back(location);
  } else if (file_type == Workspace::FileType::OpenGOAL) {
    auto maybe_tracked_file = workspace.get_tracked_og_file(params.m_textDocument.m_uri);
    if (!maybe_tracked_file) {
      return {};
    }
    const auto& tracked_file = maybe_tracked_file.value().get();
    const auto symbol = tracked_file.get_symbol_at_position(params.m_position);
    if (!symbol) {
      return {};
    }
    const auto& symbol_info = workspace.get_global_symbol_info(tracked_file, symbol.value());
    if (!symbol_info) {
      return {};
    }

    const auto& def_loc = workspace.get_symbol_def_location(tracked_file, symbol_info.value());
    if (!def_loc) {
      return {};
    }

    LSPSpec::Location location;
    location.m_uri = def_loc->file_path;
    location.m_range.m_start = {(uint32_t)def_loc->line_idx, (uint32_t)def_loc->char_idx};
    location.m_range.m_end = {(uint32_t)def_loc->line_idx, (uint32_t)def_loc->char_idx};
    locations.push_back(location);
  }

  return locations;
}
}  // namespace lsp_handlers
