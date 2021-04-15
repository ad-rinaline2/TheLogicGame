# Example of PVS-Studio rules configuration file.
# Full documentation is available at
# https://www.viva64.com/en/d/0021/
# https://www.viva64.com/en/m/0040/
#
# Filtering out messages by specifying a fragment from source code:
# //-V:textFromSourceCode:3001,3002,3003
#
# Turning off specific analyzer rules:
# //-V::3021,3022
#
# Turning off specific rule groups (X64, GA, OP, CS, MISRA):
# //-V::X64,OP
#
# Turning off specific warning levels of analyzer rules and rule groups:
# //-V::3021,OP:2,3
#
# Changing in analyzer's output message:
# //+V3022:RENAME:{oldText0:newText0},{oldText1:newText1}
#
# Appends message to analyzer's message:
# //+V3023:ADD:{Message}
#
# Excluding directories from the analysis:
# //V_EXCLUDE_PATH \thirdParty\
# //V_EXCLUDE_PATH C:\TheBestProject\thirdParty
# //V_EXCLUDE_PATH *\UE4\Engine\*
#
# Redefining levels:
# //V_LEVEL_1::501,502
# //V_LEVEL_2::522,783,579
# //V_LEVEL_3::773
#
# Rule filters should be written without '#' character.