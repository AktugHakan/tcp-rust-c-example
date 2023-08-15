# Variables
CXXFLAGS := -Wall -Werror
PROTOBUF_LINKER_FLAGS := -L/usr/local/lib -lprotobuf -labsl_log_internal_check_op -labsl_leak_check -labsl_die_if_null -labsl_log_internal_conditions -labsl_log_internal_message -labsl_examine_stack -labsl_log_internal_format -labsl_log_internal_proto -labsl_log_internal_nullguard -labsl_log_internal_log_sink_set -labsl_log_sink -labsl_log_entry -labsl_flags -labsl_flags_internal -labsl_flags_marshalling -labsl_flags_reflection -labsl_flags_private_handle_accessor -labsl_flags_commandlineflag -labsl_flags_commandlineflag_internal -labsl_flags_config -labsl_flags_program_name -labsl_log_initialize -labsl_log_globals -labsl_log_internal_globals -labsl_hash -labsl_city -labsl_low_level_hash -labsl_raw_hash_set -labsl_hashtablez_sampler -labsl_statusor -labsl_status -labsl_cord -labsl_cordz_info -labsl_cord_internal -labsl_cordz_functions -labsl_exponential_biased -labsl_cordz_handle -labsl_crc_cord_state -labsl_crc32c -labsl_crc_internal -labsl_crc_cpu_detect -labsl_bad_optional_access -labsl_str_format_internal -labsl_strerror -labsl_synchronization -labsl_graphcycles_internal -labsl_stacktrace -labsl_symbolize -labsl_debugging_internal -labsl_demangle_internal -labsl_malloc_internal -labsl_time -labsl_civil_time -labsl_time_zone -labsl_bad_variant_access -lutf8_validity -lutf8_range -labsl_strings -labsl_strings_internal -lrt -labsl_base -labsl_spinlock_wait -labsl_int128 -labsl_throw_delegate -labsl_raw_logging_internal -labsl_log_severity
LIBRARY_DIR := lib/SocketManager
LIBRARY_INCLUDE := $(LIBRARY_DIR)/include
LIBRARY_PATH := $(LIBRARY_DIR)/libSockets.a
SRC_DIR := src
BIN_DIR := build
INCLUDE_DIR := include

# Check if cross compile variable is set
ifeq ($(CROSS_COMPILE),)
	CXX := g++
else
	CXX := $(CROSS_COMPILE)g++
endif

# Files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SRC_FILES))
EXECUTABLE := $(BIN_DIR)/main

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES) $(LIBRARY_PATH)
	$(CXX) $(CXXFLAGS) -I$(LIBRARY_INCLUDE) -L$(LIBRARY_DIR) -lSockets -lpthread  -o $@ $^ $(PROTOBUF_LINKER_FLAGS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(LIBRARY_INCLUDE) -I$(INCLUDE_DIR) -c $< -o $@

$(LIBRARY_PATH):
	$(MAKE) -C $(LIBRARY_DIR)

clean:
	rm -f $(BIN_DIR)/*.o $(EXECUTABLE)
	$(MAKE) -C $(LIBRARY_DIR) clean

run: $(EXECUTABLE)
	./build/main

pull:
	cd lib/SocketManager && git pull
	
