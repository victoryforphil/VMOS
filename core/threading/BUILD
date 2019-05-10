cc_library(
    name = "vmos-threading",
    srcs = ["queue_manager.cpp","message_queue.cpp","threading.cpp"],
    hdrs = ["queue_manager.hpp","message_queue.hpp","threading.hpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//core/math:vmos-math",
        "//core/logging:vmos-logging",
    ],
)

cc_library(
    name = "vmos-queues",
    srcs = ["queue_manager.cpp","message_queue.cpp"],
    hdrs = ["queue_manager.hpp","message_queue.hpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//core/math:vmos-math",
        "//core/logging:vmos-logging",
    ],
)

cc_test(
    name = "queue-test",
    srcs = ["queue_test.cpp"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@gtest//:main",
        ":vmos-queues",
    ],
)


