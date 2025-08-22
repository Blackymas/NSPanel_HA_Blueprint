// macros.h - Utility macros for NSPanel HA Blueprint project
// Contains conditional logging macros and other utility macros

/**
 * @brief Conditional error logging macro
 * 
 * Logs an error message only if the condition is true and error logging is enabled.
 * The condition is only evaluated if ESPHOME_LOG_LEVEL includes error messages.
 * 
 * @param tag Log tag (const char*)
 * @param condition Boolean condition to check
 * @param ... Printf-style format string and arguments
 */
 #ifndef ESP_LOGE_IF
 #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_ERROR
#define ESP_LOGE_IF(tag, condition, ...) \
  do { \
    if (condition) { \
      ESP_LOGE(tag, __VA_ARGS__); \
    } \
  } while (0)
#else
#define ESP_LOGE_IF(tag, condition, ...) ((void)0)
#endif  // ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_ERROR
#endif  // ESP_LOGE_IF

/**
 * @brief Conditional warning logging macro
 * 
 * Logs a warning message only if the condition is true and warning logging is enabled.
 * The condition is only evaluated if ESPHOME_LOG_LEVEL includes warning messages.
 * 
 * @param tag Log tag (const char*)
 * @param condition Boolean condition to check
 * @param ... Printf-style format string and arguments
 */
#ifndef ESP_LOGW_IF
#if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_WARN
#define ESP_LOGW_IF(tag, condition, ...) \
  do { \
    if (condition) { \
      ESP_LOGW(tag, __VA_ARGS__); \
    } \
  } while (0)
#else
#define ESP_LOGW_IF(tag, condition, ...) ((void)0)
#endif  // ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_WARN
#endif  // ESP_LOGW_IF

/**
 * @brief Conditional info logging macro
 * 
 * Logs an info message only if the condition is true and info logging is enabled.
 * The condition is only evaluated if ESPHOME_LOG_LEVEL includes info messages.
 * 
 * @param tag Log tag (const char*)
 * @param condition Boolean condition to check
 * @param ... Printf-style format string and arguments
 */
#ifndef ESP_LOGI_IF
#if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_INFO
#define ESP_LOGI_IF(tag, condition, ...) \
  do { \
    if (condition) { \
      ESP_LOGI(tag, __VA_ARGS__); \
    } \
  } while (0)
#else
#define ESP_LOGI_IF(tag, condition, ...) ((void)0)
#endif  // ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_INFO
#endif  // ESP_LOGI_IF

/**
 * @brief Conditional debug logging macro
 * 
 * Logs a debug message only if the condition is true and debug logging is enabled.
 * The condition is only evaluated if ESPHOME_LOG_LEVEL includes debug messages.
 * 
 * @param tag Log tag (const char*)
 * @param condition Boolean condition to check
 * @param ... Printf-style format string and arguments
 */
#ifndef ESP_LOGD_IF
#if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_DEBUG
#define ESP_LOGD_IF(tag, condition, ...) \
  do { \
    if (condition) { \
      ESP_LOGD(tag, __VA_ARGS__); \
    } \
  } while (0)
#else
#define ESP_LOGD_IF(tag, condition, ...) ((void)0)
#endif  // ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_DEBUG
#endif  // ESP_LOGD_IF

/**
 * @brief Conditional config logging macro
 * 
 * Logs a config message only if the condition is true and config logging is enabled.
 * The condition is only evaluated if ESPHOME_LOG_LEVEL includes config messages.
 * 
 * @param tag Log tag (const char*)
 * @param condition Boolean condition to check
 * @param ... Printf-style format string and arguments
 */
#ifndef ESP_LOGCONFIG_IF
#if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_CONFIG
#define ESP_LOGCONFIG_IF(tag, condition, ...) \
  do { \
    if (condition) { \
      ESP_LOGCONFIG(tag, __VA_ARGS__); \
    } \
  } while (0)
#else
#define ESP_LOGCONFIG_IF(tag, condition, ...) ((void)0)
#endif  // ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_CONFIG
#endif  // ESP_LOGCONFIG_IF

/**
 * @brief Conditional verbose logging macro
 * 
 * Logs a verbose message only if the condition is true and verbose logging is enabled.
 * The condition is only evaluated if ESPHOME_LOG_LEVEL includes verbose messages.
 * 
 * @param tag Log tag (const char*)
 * @param condition Boolean condition to check
 * @param ... Printf-style format string and arguments
 */
#ifndef ESP_LOGV_IF
#if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_VERBOSE
#define ESP_LOGV_IF(tag, condition, ...) \
  do { \
    if (condition) { \
      ESP_LOGV(tag, __VA_ARGS__); \
    } \
  } while (0)
#else
#define ESP_LOGV_IF(tag, condition, ...) ((void)0)
#endif  // ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_VERBOSE
#endif  // ESP_LOGV_IF

/**
 * @brief Conditional very verbose logging macro
 * 
 * Logs a very verbose message only if the condition is true and very verbose logging is enabled.
 * The condition is only evaluated if ESPHOME_LOG_LEVEL includes very verbose messages.
 * 
 * @param tag Log tag (const char*)
 * @param condition Boolean condition to check
 * @param ... Printf-style format string and arguments
 */
#ifndef ESP_LOGVV_IF
#if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_VERY_VERBOSE
#define ESP_LOGVV_IF(tag, condition, ...) \
  do { \
    if (condition) { \
      ESP_LOGVV(tag, __VA_ARGS__); \
    } \
  } while (0)
#else
#define ESP_LOGVV_IF(tag, condition, ...) ((void)0)
#endif  // ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_VERY_VERBOSE
#endif  // ESP_LOGVV_IF

// Example usage with your version comparison code:
/*
ESP_LOGE_IF("${TAG_CORE}", 
            not compare_versions("${version}", version_tft->state.c_str()), 
            "TFT version mismatch!");

ESP_LOGD("${TAG_CORE}", "  Blueprint: %s", version_blueprint->state.c_str());

ESP_LOGE_IF("${TAG_CORE}", 
            not compare_versions("${version}", version_blueprint->state.c_str()), 
            "Blueprint version mismatch!");
*/
