#pragma once

#include "common/common_types.h"
#include <string>
#include <optional>

// Discord RPC
struct DiscordRichPresence;
extern int gDiscordRpcEnabled;
extern int64_t gStartTime;
namespace jak1 {
/*!
 * Initialize global variables based on command line parameters
 */
void InitParms(int argc, const char* const* argv);
/*!
 * Initialize the I/O Processor
 */
void InitIOP();
/*!
 * Initialze GOAL Runtime
 */
int InitMachine();
/*!
 * Shutdown GOAL runtime.
 */
int ShutdownMachine();

void InitMachineScheme();



extern char* intToStr(int data);

struct DiscordInfo {
  u32 fuel;
  u32 money_total;
  u32 buzzer_total;
  u32 deaths;
  u32 status;
  u32 level;
  u32 cutscene;   // check if cutscene is playing
  u32 ogreboss;   // are we fighting ogreboss?
  u32 plantboss;  // are we fighting plant-boss?
  u32 racer;      // are we driving the zoomer?
  u32 flutflut;   // are we riding on flut flut?
  u32 time_of_day;
};

struct HttpStruct {
  u32 fuel;
  int target1X;
  int target1Y;
  int target1Z;
};

struct HttpStructNice {
int num_cells;
int target1X;
int target1Y;
int target1Z;
};

// To speedup finding the auto-splitter block in GOAL memory
// all this has is a marker for LiveSplit to find, and then the pointer
// to the symbol
struct AutoSplitterBlock {
  const char marker[20] = "UnLiStEdStRaTs_JaK1";
  u64 pointer_to_symbol = 0;
};
extern AutoSplitterBlock gAutoSplitterBlock;
extern std::optional<jak1::HttpStructNice> g_http_info;

}  // namespace jak1
