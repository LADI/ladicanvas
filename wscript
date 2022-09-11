#! /usr/bin/env python
# encoding: utf-8

LANV_API_VERSION = '0.1.0'

def options(opt):
    # options provided by the modules
#    opt.load('compiler_c')
    opt.load('compiler_cxx')
    opt.load('autooptions')

def configure(conf):
#    conf.load('compiler_c')
    conf.load('compiler_cxx')

    conf.check_cfg(package='libgnomecanvasmm-2.6', mandatory=True, args='--cflags --libs')

def build(bld):
    lib = bld(features=['cxx', 'cxxshlib']) # TODO: convert C++ to plain C
    lib.defines = 'HAVE_CONFIG_H'
    lib.includes = []
    lib.name = 'lib'
    lib.target = 'lanv'
    lib.install_path = '${LIBDIR}'
    lib.use = ['LIBGNOMECANVASMM-2.6']

    lib.source = [
        'src/lanv.cpp',
        'src/Module.cpp',
        'src/Item.cpp',
        'src/Port.cpp',
        'src/Connection.cpp',
        'src/Ellipse.cpp',
        'src/Connectable.cpp',
        ]

    lib.vnum = bld.env['LANV_API_VERSION']

    lib.env.append_value('CPPFLAGS', '-fvisibility=hidden')
