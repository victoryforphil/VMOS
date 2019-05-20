load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
# This com_google_protobuf repository is required for proto_library rule.
# It provides the protocol compiler binary (i.e., protoc).
http_archive(
    name = "com_google_protobuf",
    strip_prefix = "protobuf-master",
    urls = ["https://github.com/protocolbuffers/protobuf/archive/master.zip"],
)
# This com_google_protobuf_cc repository is required for cc_proto_library
# rule. It provides protobuf C++ runtime. Note that it actually is the same
# repo as com_google_protobuf but has to be given a different name as
# required by bazel.
http_archive(
    name = "com_google_protobuf_cc",
    strip_prefix = "protobuf-master",
    urls = ["https://github.com/protocolbuffers/protobuf/archive/master.zip"],
)
# Similar to com_google_protobuf_cc but for Java (i.e., java_proto_library).
http_archive(
    name = "com_google_protobuf_java",
    strip_prefix = "protobuf-master",
    urls = ["https://github.com/protocolbuffers/protobuf/archive/master.zip"],
)
# Similar to com_google_protobuf_cc but for Java lite. If you are building
# for Android, the lite version should be prefered because it has a much
# smaller code size.
http_archive(
    name = "com_google_protobuf_javalite",
    strip_prefix = "protobuf-javalite",
    urls = ["https://github.com/protocolbuffers/protobuf/archive/javalite.zip"],
)
http_archive(
    name = "bazel_skylib",
    sha256 = "bbccf674aa441c266df9894182d80de104cabd19be98be002f6d478aaa31574d",
    strip_prefix = "bazel-skylib-2169ae1c374aab4a09aa90e65efe1a3aad4e279b",
    urls = ["https://github.com/bazelbuild/bazel-skylib/archive/2169ae1c374aab4a09aa90e65efe1a3aad4e279b.tar.gz"],
)
load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")
protobuf_deps()
load("@bazel_skylib//lib:versions.bzl", "versions")
versions.check(minimum_bazel_version = "0.5.4")
new_local_repository(
      name = "aarch64_compiler",
      path = "/",
      build_file = "aarchcompiler.BUILD",
    )
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "gtest",
    url = "https://github.com/google/googletest/archive/release-1.7.0.zip",
    sha256 = "b58cb7547a28b2c718d1e38aee18a3659c9e3ff52440297e965f5edffe34b6d0",
    build_file = "@//:gtest.BUILD",
    strip_prefix = "googletest-release-1.7.0",
)
