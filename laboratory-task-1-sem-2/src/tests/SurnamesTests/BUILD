## src/tests/SurnamesTests/BUILD

filegroup(
    name = "ReadSurnamesFile",
    srcs = [
        "ReadSurnames/test_read_surnames.txt"
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "SurnamesTests",
    srcs = ["SurnamesTests.cpp"],
    data = ["//src/tests/SurnamesTests:ReadSurnamesFile"],
    visibility = ["//visibility:public"],
    deps = [
        "@googletest//:gtest_main",
        "//src/Surnames:Surnames",
    ]
)
