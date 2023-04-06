## Simple password generator based on TOTP in pure C without dependencies

Project based on [c_otp](https://github.com/fmount/c_otp) and [tiny-HMAC-c](https://github.com/kokke/tiny-HMAC-c) and used by me to generate Wi-Fi passwords for guest network.<br>
The output executable is only ~25kb (on mips32 when dynamically-linked with uclibc).

<b>Usage:</b>
```shell
$ ./wifi_opt [b32_secretkey]
```

<b>Example:</b>
```shell
$ ./wifi_opt aaaaaaaaaaaaaaaa
0x13b11aa009_304)
```

<b>Password format:</b>
`hex(code*code) _ (code % 997) )` where code is 6-digit totp.<br>
Password example: 0x13b11aa009_304) (key - `aaaaaaaaaaaaaaaa`, time - `1680774681`)