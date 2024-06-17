## src/tests/NumbersTests/BUILD

filegroup(
    name = "CheckFileFiles",
    srcs = [
        "CheckFile/normal.txt",
        "CheckFile/notOpened.txt",
        "CheckFile/empty.txt",
    ],
    visibility = ["//visibility:public"],
)

filegroup(
    name = "ReadIntFiles",
    srcs = [
        "ReadInt/posInt.txt",
        "ReadInt/negInt.txt",
        "ReadInt/diffInt.txt",
        "ReadInt/notInt.txt",
    ],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "NumbersTests",
    srcs = ["NumbersTests.cpp"],
    data = [
        "//src/tests/NumbersTests:CheckFileFiles",
        "//src/tests/NumbersTests:ReadIntFiles",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@googletest//:gtest_main",
        "//src/Numbers:Numbers",
    ]
)
