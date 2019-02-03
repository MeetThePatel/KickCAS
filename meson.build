project ('KickCAS', 'cpp',
	default_options : ['cpp_std=c++17'])

incdir = include_directories('include')

cppfiles_raw = run_command ('.script/grabber.sh')
cppfiles = cppfiles_raw.stdout().strip().split('\n')

executable('KickCAS', cppfiles, include_directories: incdir)

