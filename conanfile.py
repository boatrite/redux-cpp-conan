from conans import ConanFile, CMake, tools


class ReduxCppConanConan(ConanFile):
    name = "redux-cpp-conan"
    version = "0.1"
    no_copy_source = True

    def source(self):
        self.run("git clone https://github.com/sutbult/redux-cpp.git")

    def package(self):
        self.copy("*.hpp", dst="include", src="redux-cpp/include")
