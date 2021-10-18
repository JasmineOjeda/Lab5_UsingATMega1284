# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).
tests = [ {'description': 'A:0 => C:0x40',
    'steps': [ {'inputs': [('PINA', 0xFF)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x40)],
    },
    {'description': 'A:1 => C:0x60',
    'steps': [ {'inputs': [('PINA', 0xFE)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x60)],
    },
    {'description': 'A:2 => C:0x60',
    'steps': [ {'inputs': [('PINA', 0xFD)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x60)],
    },
    {'description': 'A:3 => C:0x70',
    'steps': [ {'inputs': [('PINA', 0xFC)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x70)],
    },
    {'description': 'A:4 => C:0x70',
    'steps': [ {'inputs': [('PINA', 0xFB)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x70)],
    },
    {'description': 'A:5 => C:0x38',
    'steps': [ {'inputs': [('PINA', 0xFA)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x38)],
    },
    {'description': 'A:6 => C:0x38',
    'steps': [ {'inputs': [('PINA', 0xF9)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x38)],
    },
    {'description': 'A:7 => C:0x3C',
    'steps': [ {'inputs': [('PINA', 0xF8)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x3C)],
    },
    {'description': 'A:8 => C:0x3C',
    'steps': [ {'inputs': [('PINA', 0xF7)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x3C)],
    },
    {'description': 'A:9 => C:0x3C',
    'steps': [ {'inputs': [('PINA', 0xF6)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x3C)],
    },
    {'description': 'A:10 => C:0x3E',
    'steps': [ {'inputs': [('PINA', 0xF5)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x3E)],
    },
    {'description': 'A:11 => C:0x3E',
    'steps': [ {'inputs': [('PINA', 0xF4)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x3E)],
    },
    {'description': 'A:12 => C:0x3E',
    'steps': [ {'inputs': [('PINA', 0xF3)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x3E)],
    },
    {'description': 'A:13 => C:0x3F',
    'steps': [ {'inputs': [('PINA', 0xF2)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x3F)],
    },
    {'description': 'A:14 => C:0x3F',
    'steps': [ {'inputs': [('PINA', 0xF1)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x3F)],
    },
    {'description': 'A:15 => C:0x3F',
    'steps': [ {'inputs': [('PINA', 0xF0)], 'iterations': 5 } ],
    'expected': [('PORTC', 0x3F)],
    },
    ]

# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
