#!/usr/bin/env python
# encoding: utf-8

APPLICATION_NAME='theory'

top = '.'
out = 'build'

def options(opt):
    opt.load('compiler_cxx unittest_gtest')

def configure(conf):
    conf.load('compiler_cxx boost unittest_gtest doxygen')

    #conf.env.CXXFLAGS = ['-std=c++0x', '-Wall', '-g']
    conf.env.CXXFLAGS = ['-std=c++0x', '-Wall', '-O3']

    conf.check_boost(lib='regex', mt=True, static=True)

def build(bld):

    bld.stlib(
        features    = 'cxx',
        source      = [
                        'src/note.cc',
                        'src/scale.cc',
                        'src/scale_template.cc',
                      ],
        includes    = 'include',
        use = 'BOOST',
        target=APPLICATION_NAME)

    bld.program(
        features    = 'gtest',
        source      = [
                        'src/tests/note_unittest.cc', 'src/note.cc',
                        'src/tests/scale_unittest.cc', 'src/scale.cc',
                        'src/tests/scale_template_unittest.cc', 'src/scale_template.cc',
                        'src/tests/helpers_unittest.cc',
                      ],
        includes    = 'src include',
        use         = 'BOOST',
        target      = APPLICATION_NAME+'_test')

    # Build documentation
    bld(features = 'doxygen',
        doxyfile = 'Doxyfile')
