#!/usr/bin/env python
# encoding: utf-8

APPLICATION_NAME='theory'

VERSION_MAJOR = 0
VERSION_MINOR = 1
VERSION_REVISION = 0


VERSION=str(VERSION_MAJOR)+'.'+str(VERSION_MINOR)+'.'+str(VERSION_REVISION)

top = '.'
out = 'build'

def options(opt):
    opt.load('compiler_cxx boost unittest_gtest doxygen')

def configure(conf):
    conf.load('compiler_cxx boost unittest_gtest doxygen')
    conf.env.CXXFLAGS = [ '-std=c++0x', '-g']

    conf.check_boost(lib='regex program_options', mt=True, static=True)

    conf.define('VERSION', VERSION)
    conf.define('APPLICATION_NAME', APPLICATION_NAME)

    conf.write_config_header('include/config.h')


def build(bld):

    bld.stlib(
        features    = 'cxx',
        source      = [
                        'src/note.cc',
                        'src/scale.cc',
                        'src/scale_template.cc',
                        'src/theory.cc',
                      ],
        includes    = 'include',
        #use = 'BOOST',
        target=APPLICATION_NAME)

    bld.program(
        features    = 'gtest',
        source      = [
                        'src/tests/note_unittest.cc', 'src/note.cc',
                        'src/tests/scale_unittest.cc', 'src/scale.cc',
                        'src/tests/scale_template_unittest.cc', 'src/scale_template.cc',
                        'src/tests/theory_unittest.cc', 'src/theory.cc',
                      ],
        includes    = 'src include',
        use         = 'BOOST',
        target      = APPLICATION_NAME+'_test')

    # Build documentation
    bld(features = 'doxygen',
        doxyfile = 'Doxyfile')
