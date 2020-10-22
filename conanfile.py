from conans import ConanFile, CMake


class TermTableConan(ConanFile):
    name = "term_table"
    version = "0.0.1"
    license = "to be defined later"
    url = "https://github.com/ukhegg/term_table.git"
    description = "Library for drawing symbolic tables"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = "shared=True"
    generators = "cmake"
    requires = "gsl_microsoft/20180102@bincrafters/stable"
    build_requires = "Catch2/2.11.1@catchorg/stable"
    def source(self):
        self.run("git clone -b v{} {} {}".format(self.version, self.url, self.source_folder))

    def build(self):
        if self.settings.build_type == 'Debug':
            self.settings.compiler.runtime = 'MDd'
        elif self.settings.build_type in ['Release', 'RelWithDebInfo', 'MinSizeRel']:
            self.settings.compiler.runtime = 'MD'
        else:
            raise ("unknown build type:{}".format(self.settings.build_type))

        cmake = CMake(self)
        if self.options.shared == 'True':
            cmake.definitions["BUILD_SHARED_LIBS"] = "ON"
        cmake.configure(source_dir='.')
        cmake.build()
        cmake.test()

    def package(self):
        self.copy("*.h(pp)?", src="src/term_table")
        self.copy("*/term_table.lib", dst="lib", keep_path=False)
        self.copy("*/term_table.dll", dst="bin", keep_path=False)
        self.copy("*/term_table.pdb", dst="bin", keep_path=False)
        self.copy("*/term_table.dylib*", dst="lib", keep_path=False)
        self.copy("*/term_table.so", dst="lib", keep_path=False)
        self.copy("*/term_table.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["term_table"]

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.pdb", dst="bin", src="bin")
        self.copy("*.so", dst="bin", src="bin")
        self.copy("*.a", dst="lib", src="lib")
        self.copy("*.lib", dst="lib", src="lib")
        self.copy("*.dylib*", dst="lib", src="lib")
