man_pages_sources = ['false.1.scd',
                     'true.1.scd',
                     'uname.1.scd',
                     'sleep.1.scd']

if scdoc_dep.found()
    foreach man_page_source : man_pages_sources
        topic = man_page_source.split('.')[0]
        section = man_page_source.split('.')[1]
        output = '@0@.@1@'.format(topic, section)
        custom_target(output,
                      input: man_page_source,
                      output: output,
                      command: scdoc_dep,
                      feed: true,
                      capture: true,
                      install: true,
                      install_dir: get_option('mandir') / 'man' + section)
        endforeach
endif
