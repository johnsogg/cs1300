
def enum(**enums):
    return type('Enum', (), enums)

Decisions = enum(MOVE='move', REST='rest', EAT='eat')
