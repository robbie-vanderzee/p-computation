# pcomputation::build::bazel

load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")
load("@bazel_skylib//lib:paths.bzl", "paths")

def configure_submodule_dependencies(repo_alias = "@pcomputation", repo_path = "./"):
    maybe(
        native.local_repository,
        name = "gtest",
        path = paths.join(repo_path, "includes/gtest"),
    )
    maybe(
        native.new_local_repository,
        name = "spdlog",
        build_file = repo_alias + "//:build/includes/spdlog/BUILD.bazel",
        path = paths.join(repo_path, "includes/spdlog"),
    )
