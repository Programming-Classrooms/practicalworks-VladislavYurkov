## src/main/BUILD

filegroup(
    name = "files",
    srcs = [
        "Numbers.txt",
        "Strings.txt",
        "result.bin",
    ],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "cpp_app",
    srcs = ["main.cpp"],
    data = ["//src/main:files"],
    deps = [
        "//src/Numbers:Numbers",
        "//src/Surnames:Surnames",
        "//src/Employee:Employee",
    ],
)
