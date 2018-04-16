{
    "targets": [
        {
            "target_name": "cryptonote",
            "sources": [
                "src/main.cpp",
                "src/crypto/crypto.cpp",
                "src/crypto/crypto-ops.c",
                "src/crypto/crypto-ops-data.c",
                "src/crypto/hash.c",
                "src/crypto/keccak.c",
                "src/crypto/blake256.c",
                "src/crypto/hash-extra-blake.c",
                "src/crypto/groestl.c",
                "src/crypto/hash-extra-groestl.c",
                "src/crypto/jh.c",
                "src/crypto/hash-extra-jh.c",
                "src/crypto/skein.c",
                "src/crypto/hash-extra-skein.c",
                "src/crypto/slow-hash2.cpp",
                "src/crypto/slow-hash.c",
                "src/crypto/random.c",
                "src/crypto/oaes_lib.c",
                "src/Common/Base58.cpp",
            ],
            "include_dirs": [
                "src",
                "<!(node -e \"require('nan')\")",
            ],
            "cflags_c": [
                "-std=gnu11 -march=native -fPIC -m64"
            ],
            "cflags_cc": [
                "-std=gnu++11 -fPIC -m64"
            ],
        }
    ]
}
