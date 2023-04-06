cmake_minimum_required(VERSION 2.6)
project(CWifiOtp C)

# the binary
add_executable(wifi_opt src/main.c src/utils.c src/rfc4226.c src/rfc6238.c src/sha1.c src/hmac.c src/math_utils.c)
target_link_libraries(wifi_opt)
