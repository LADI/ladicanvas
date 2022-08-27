#! /usr/bin/env python
# encoding: utf-8

LANV_API_VERSION = '0.1.0'

def options(opt):
    # options provided by the modules
    opt.load('compiler_c')
    opt.load('autooptions')

def configure(conf):
    conf.load('compiler_c')

def build(bld):
    lib = bld(features=['c', 'cshlib'])
    lib.defines = 'HAVE_CONFIG_H'
    lib.includes = []
    lib.name = 'lib'
    lib.target = 'lanv'
    lib.install_path = '${LIBDIR}'
    lib.use = []

    lib.source = [
        'canvas.c',
#        'module.c',
#        'item.c',
#        'port.c',
#        'connection.c',
#        'ellipse.c',
#        'connectable.c',
        ]

    lib.vnum = bld.env['LANV_API_VERSION']

    lib.env.append_value('CPPFLAGS', '-fvisibility=hidden')
