HELP = """
Usage: python cscaffolder.py <command> <data-struct> <type>

Commands:
  gen     Generate a new data structure and type implementation
  -h, --help  Show this help message and exit

Arguments:
  <command>     The command to execute (either 'gen' or '-h'/'--help')
  <data-struct> The name of the data structure to generate (e.g., 'queue', 'stack', 'list')
  <type>        The type of the data structure elements (e.g., 'int', 'string', 'custom_type')

Description:
  The cscaffolder tool is used to generate boilerplate code for common data structures
  and their corresponding types. This can help speed up the development process when
  working on new projects that require these data structures.

  To generate a new data structure and type implementation, use the 'gen' command
  followed by the name of the data structure and the type of its elements.

  For example:
    python cscaffolder.py gen queue int

  This will generate a new queue data structure implementation that can hold 'int' elements.

  If you need help or want to see this usage information again, use the '-h' or '--help' command.
"""