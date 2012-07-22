/**************************************************
 *
 * Populated interrupt vector table for the
 * IAR C/C++ Compiler for Renesas RX
 *
 * Copyright 2010 IAR Systems AB.
 *
 **************************************************/

#include "stdlib.h"
#pragma language=extended
typedef void (__interrupt *__fp)();

void OSTickISR (void);
void OSCtxSw   (void);
void AdcIsr    (void);

#if 0
__noreturn __interrupt void default_handler()
{
  abort();
}
#endif
__noreturn __interrupt void default_handler()
{
  static unsigned int unexpected_interrupt_count = 0;

  unexpected_interrupt_count++;
}

__interrupt void __interrupt_0();
#pragma weak __interrupt_0 = default_handler
__interrupt void __interrupt_1();
#pragma weak __interrupt_1 = default_handler
__interrupt void __interrupt_2();
#pragma weak __interrupt_2 = default_handler
__interrupt void __interrupt_3();
#pragma weak __interrupt_3 = default_handler
__interrupt void __interrupt_4();
#pragma weak __interrupt_4 = default_handler
__interrupt void __interrupt_5();
#pragma weak __interrupt_5 = default_handler
__interrupt void __interrupt_6();
#pragma weak __interrupt_6 = default_handler
__interrupt void __interrupt_7();
#pragma weak __interrupt_7 = default_handler
__interrupt void __interrupt_8();
#pragma weak __interrupt_8 = default_handler
__interrupt void __interrupt_9();
#pragma weak __interrupt_9 = default_handler
__interrupt void __interrupt_10();
#pragma weak __interrupt_10 = default_handler
__interrupt void __interrupt_11();
#pragma weak __interrupt_11 = default_handler
__interrupt void __interrupt_12();
#pragma weak __interrupt_12 = default_handler
__interrupt void __interrupt_13();
#pragma weak __interrupt_13 = default_handler
__interrupt void __interrupt_14();
#pragma weak __interrupt_14 = default_handler
__interrupt void __interrupt_15();
#pragma weak __interrupt_15 = default_handler
__interrupt void __interrupt_16();
#pragma weak __interrupt_16 = default_handler
__interrupt void __interrupt_17();
#pragma weak __interrupt_17 = default_handler
__interrupt void __interrupt_18();
#pragma weak __interrupt_18 = default_handler
__interrupt void __interrupt_19();
#pragma weak __interrupt_19 = default_handler
__interrupt void __interrupt_20();
#pragma weak __interrupt_20 = default_handler
__interrupt void __interrupt_21();
#pragma weak __interrupt_21 = default_handler
__interrupt void __interrupt_22();
#pragma weak __interrupt_22 = default_handler
__interrupt void __interrupt_23();
#pragma weak __interrupt_23 = default_handler
__interrupt void __interrupt_24();
#pragma weak __interrupt_24 = default_handler
__interrupt void __interrupt_25();
#pragma weak __interrupt_25 = default_handler
__interrupt void __interrupt_26();
#pragma weak __interrupt_26 = default_handler
__interrupt void __interrupt_27();
#pragma weak __interrupt_27 = default_handler
__interrupt void __interrupt_28();
#pragma weak __interrupt_28 = default_handler
__interrupt void __interrupt_29();
#pragma weak __interrupt_29 = default_handler
__interrupt void __interrupt_30();
#pragma weak __interrupt_30 = default_handler
__interrupt void __interrupt_31();
#pragma weak __interrupt_31 = default_handler
__interrupt void __interrupt_32();
#pragma weak __interrupt_32 = default_handler
__interrupt void __interrupt_33();
#pragma weak __interrupt_33 = default_handler
__interrupt void __interrupt_34();
#pragma weak __interrupt_34 = default_handler
__interrupt void __interrupt_35();
#pragma weak __interrupt_35 = default_handler
__interrupt void __interrupt_36();
#pragma weak __interrupt_36 = default_handler
__interrupt void __interrupt_37();
#pragma weak __interrupt_37 = default_handler
__interrupt void __interrupt_38();
#pragma weak __interrupt_38 = default_handler
__interrupt void __interrupt_39();
#pragma weak __interrupt_39 = default_handler
__interrupt void __interrupt_40();
#pragma weak __interrupt_40 = default_handler
__interrupt void __interrupt_41();
#pragma weak __interrupt_41 = default_handler
__interrupt void __interrupt_42();
#pragma weak __interrupt_42 = default_handler
__interrupt void __interrupt_43();
#pragma weak __interrupt_43 = default_handler
__interrupt void __interrupt_44();
#pragma weak __interrupt_44 = default_handler
__interrupt void __interrupt_45();
#pragma weak __interrupt_45 = default_handler
__interrupt void __interrupt_46();
#pragma weak __interrupt_46 = default_handler
__interrupt void __interrupt_47();
#pragma weak __interrupt_47 = default_handler
__interrupt void __interrupt_48();
#pragma weak __interrupt_48 = default_handler
__interrupt void __interrupt_49();
#pragma weak __interrupt_49 = default_handler
__interrupt void __interrupt_50();
#pragma weak __interrupt_50 = default_handler
__interrupt void __interrupt_51();
#pragma weak __interrupt_51 = default_handler
__interrupt void __interrupt_52();
#pragma weak __interrupt_52 = default_handler
__interrupt void __interrupt_53();
#pragma weak __interrupt_53 = default_handler
__interrupt void __interrupt_54();
#pragma weak __interrupt_54 = default_handler
__interrupt void __interrupt_55();
#pragma weak __interrupt_55 = default_handler
__interrupt void __interrupt_56();
#pragma weak __interrupt_56 = default_handler
__interrupt void __interrupt_57();
#pragma weak __interrupt_57 = default_handler
__interrupt void __interrupt_58();
#pragma weak __interrupt_58 = default_handler
__interrupt void __interrupt_59();
#pragma weak __interrupt_59 = default_handler
__interrupt void __interrupt_60();
#pragma weak __interrupt_60 = default_handler
__interrupt void __interrupt_61();
#pragma weak __interrupt_61 = default_handler
__interrupt void __interrupt_62();
#pragma weak __interrupt_62 = default_handler
__interrupt void __interrupt_63();
#pragma weak __interrupt_63 = default_handler
__interrupt void __interrupt_64();
#pragma weak __interrupt_64 = default_handler
__interrupt void __interrupt_65();
#pragma weak __interrupt_65 = default_handler
__interrupt void __interrupt_66();
#pragma weak __interrupt_66 = default_handler
__interrupt void __interrupt_67();
#pragma weak __interrupt_67 = default_handler
__interrupt void __interrupt_68();
#pragma weak __interrupt_68 = default_handler
__interrupt void __interrupt_69();
#pragma weak __interrupt_69 = default_handler
__interrupt void __interrupt_70();
#pragma weak __interrupt_70 = default_handler
__interrupt void __interrupt_71();
#pragma weak __interrupt_71 = default_handler
__interrupt void __interrupt_72();
#pragma weak __interrupt_72 = default_handler
__interrupt void __interrupt_73();
#pragma weak __interrupt_73 = default_handler
__interrupt void __interrupt_74();
#pragma weak __interrupt_74 = default_handler
__interrupt void __interrupt_75();
#pragma weak __interrupt_75 = default_handler
__interrupt void __interrupt_76();
#pragma weak __interrupt_76 = default_handler
__interrupt void __interrupt_77();
#pragma weak __interrupt_77 = default_handler
__interrupt void __interrupt_78();
#pragma weak __interrupt_78 = default_handler
__interrupt void __interrupt_79();
#pragma weak __interrupt_79 = default_handler
__interrupt void __interrupt_80();
#pragma weak __interrupt_80 = default_handler
__interrupt void __interrupt_81();
#pragma weak __interrupt_81 = default_handler
__interrupt void __interrupt_82();
#pragma weak __interrupt_82 = default_handler
__interrupt void __interrupt_83();
#pragma weak __interrupt_83 = default_handler
__interrupt void __interrupt_84();
#pragma weak __interrupt_84 = default_handler
__interrupt void __interrupt_85();
#pragma weak __interrupt_85 = default_handler
__interrupt void __interrupt_86();
#pragma weak __interrupt_86 = default_handler
__interrupt void __interrupt_87();
#pragma weak __interrupt_87 = default_handler
__interrupt void __interrupt_88();
#pragma weak __interrupt_88 = default_handler
__interrupt void __interrupt_89();
#pragma weak __interrupt_89 = default_handler
__interrupt void __interrupt_90();
#pragma weak __interrupt_90 = default_handler
__interrupt void __interrupt_91();
#pragma weak __interrupt_91 = default_handler
__interrupt void __interrupt_92();
#pragma weak __interrupt_92 = default_handler
__interrupt void __interrupt_93();
#pragma weak __interrupt_93 = default_handler
__interrupt void __interrupt_94();
#pragma weak __interrupt_94 = default_handler
__interrupt void __interrupt_95();
#pragma weak __interrupt_95 = default_handler
__interrupt void __interrupt_96();
#pragma weak __interrupt_96 = default_handler
__interrupt void __interrupt_97();
#pragma weak __interrupt_97 = default_handler
__interrupt void __interrupt_98();
#pragma weak __interrupt_98 = default_handler
__interrupt void __interrupt_99();
#pragma weak __interrupt_99 = default_handler
__interrupt void __interrupt_100();
#pragma weak __interrupt_100 = default_handler
__interrupt void __interrupt_101();
#pragma weak __interrupt_101 = default_handler
__interrupt void __interrupt_102();
#pragma weak __interrupt_102 = default_handler
__interrupt void __interrupt_103();
#pragma weak __interrupt_103 = default_handler
__interrupt void __interrupt_104();
#pragma weak __interrupt_104 = default_handler
__interrupt void __interrupt_105();
#pragma weak __interrupt_105 = default_handler
__interrupt void __interrupt_106();
#pragma weak __interrupt_106 = default_handler
__interrupt void __interrupt_107();
#pragma weak __interrupt_107 = default_handler
__interrupt void __interrupt_108();
#pragma weak __interrupt_108 = default_handler
__interrupt void __interrupt_109();
#pragma weak __interrupt_109 = default_handler
__interrupt void __interrupt_110();
#pragma weak __interrupt_110 = default_handler
__interrupt void __interrupt_111();
#pragma weak __interrupt_111 = default_handler
__interrupt void __interrupt_112();
#pragma weak __interrupt_112 = default_handler
__interrupt void __interrupt_113();
#pragma weak __interrupt_113 = default_handler
__interrupt void __interrupt_114();
#pragma weak __interrupt_114 = default_handler
__interrupt void __interrupt_115();
#pragma weak __interrupt_115 = default_handler
__interrupt void __interrupt_116();
#pragma weak __interrupt_116 = default_handler
__interrupt void __interrupt_117();
#pragma weak __interrupt_117 = default_handler
__interrupt void __interrupt_118();
#pragma weak __interrupt_118 = default_handler
__interrupt void __interrupt_119();
#pragma weak __interrupt_119 = default_handler
__interrupt void __interrupt_120();
#pragma weak __interrupt_120 = default_handler
__interrupt void __interrupt_121();
#pragma weak __interrupt_121 = default_handler
__interrupt void __interrupt_122();
#pragma weak __interrupt_122 = default_handler
__interrupt void __interrupt_123();
#pragma weak __interrupt_123 = default_handler
__interrupt void __interrupt_124();
#pragma weak __interrupt_124 = default_handler
__interrupt void __interrupt_125();
#pragma weak __interrupt_125 = default_handler
__interrupt void __interrupt_126();
#pragma weak __interrupt_126 = default_handler
__interrupt void __interrupt_127();
#pragma weak __interrupt_127 = default_handler
__interrupt void __interrupt_128();
#pragma weak __interrupt_128 = default_handler
__interrupt void __interrupt_129();
#pragma weak __interrupt_129 = default_handler
__interrupt void __interrupt_130();
#pragma weak __interrupt_130 = default_handler
__interrupt void __interrupt_131();
#pragma weak __interrupt_131 = default_handler
__interrupt void __interrupt_132();
#pragma weak __interrupt_132 = default_handler
__interrupt void __interrupt_133();
#pragma weak __interrupt_133 = default_handler
__interrupt void __interrupt_134();
#pragma weak __interrupt_134 = default_handler
__interrupt void __interrupt_135();
#pragma weak __interrupt_135 = default_handler
__interrupt void __interrupt_136();
#pragma weak __interrupt_136 = default_handler
__interrupt void __interrupt_137();
#pragma weak __interrupt_137 = default_handler
__interrupt void __interrupt_138();
#pragma weak __interrupt_138 = default_handler
__interrupt void __interrupt_139();
#pragma weak __interrupt_139 = default_handler
__interrupt void __interrupt_140();
#pragma weak __interrupt_140 = default_handler
__interrupt void __interrupt_141();
#pragma weak __interrupt_141 = default_handler
__interrupt void __interrupt_142();
#pragma weak __interrupt_142 = default_handler
__interrupt void __interrupt_143();
#pragma weak __interrupt_143 = default_handler
__interrupt void __interrupt_144();
#pragma weak __interrupt_144 = default_handler
__interrupt void __interrupt_145();
#pragma weak __interrupt_145 = default_handler
__interrupt void __interrupt_146();
#pragma weak __interrupt_146 = default_handler
__interrupt void __interrupt_147();
#pragma weak __interrupt_147 = default_handler
__interrupt void __interrupt_148();
#pragma weak __interrupt_148 = default_handler
__interrupt void __interrupt_149();
#pragma weak __interrupt_149 = default_handler
__interrupt void __interrupt_150();
#pragma weak __interrupt_150 = default_handler
__interrupt void __interrupt_151();
#pragma weak __interrupt_151 = default_handler
__interrupt void __interrupt_152();
#pragma weak __interrupt_152 = default_handler
__interrupt void __interrupt_153();
#pragma weak __interrupt_153 = default_handler
__interrupt void __interrupt_154();
#pragma weak __interrupt_154 = default_handler
__interrupt void __interrupt_155();
#pragma weak __interrupt_155 = default_handler
__interrupt void __interrupt_156();
#pragma weak __interrupt_156 = default_handler
__interrupt void __interrupt_157();
#pragma weak __interrupt_157 = default_handler
__interrupt void __interrupt_158();
#pragma weak __interrupt_158 = default_handler
__interrupt void __interrupt_159();
#pragma weak __interrupt_159 = default_handler
__interrupt void __interrupt_160();
#pragma weak __interrupt_160 = default_handler
__interrupt void __interrupt_161();
#pragma weak __interrupt_161 = default_handler
__interrupt void __interrupt_162();
#pragma weak __interrupt_162 = default_handler
__interrupt void __interrupt_163();
#pragma weak __interrupt_163 = default_handler
__interrupt void __interrupt_164();
#pragma weak __interrupt_164 = default_handler
__interrupt void __interrupt_165();
#pragma weak __interrupt_165 = default_handler
__interrupt void __interrupt_166();
#pragma weak __interrupt_166 = default_handler
__interrupt void __interrupt_167();
#pragma weak __interrupt_167 = default_handler
__interrupt void __interrupt_168();
#pragma weak __interrupt_168 = default_handler
__interrupt void __interrupt_169();
#pragma weak __interrupt_169 = default_handler
__interrupt void __interrupt_170();
#pragma weak __interrupt_170 = default_handler
__interrupt void __interrupt_171();
#pragma weak __interrupt_171 = default_handler
__interrupt void __interrupt_172();
#pragma weak __interrupt_172 = default_handler
__interrupt void __interrupt_173();
#pragma weak __interrupt_173 = default_handler
__interrupt void __interrupt_174();
#pragma weak __interrupt_174 = default_handler
__interrupt void __interrupt_175();
#pragma weak __interrupt_175 = default_handler
__interrupt void __interrupt_176();
#pragma weak __interrupt_176 = default_handler
__interrupt void __interrupt_177();
#pragma weak __interrupt_177 = default_handler
__interrupt void __interrupt_178();
#pragma weak __interrupt_178 = default_handler
__interrupt void __interrupt_179();
#pragma weak __interrupt_179 = default_handler
__interrupt void __interrupt_180();
#pragma weak __interrupt_180 = default_handler
__interrupt void __interrupt_181();
#pragma weak __interrupt_181 = default_handler
__interrupt void __interrupt_182();
#pragma weak __interrupt_182 = default_handler
__interrupt void __interrupt_183();
#pragma weak __interrupt_183 = default_handler
__interrupt void __interrupt_184();
#pragma weak __interrupt_184 = default_handler
__interrupt void __interrupt_185();
#pragma weak __interrupt_185 = default_handler
__interrupt void __interrupt_186();
#pragma weak __interrupt_186 = default_handler
__interrupt void __interrupt_187();
#pragma weak __interrupt_187 = default_handler
__interrupt void __interrupt_188();
#pragma weak __interrupt_188 = default_handler
__interrupt void __interrupt_189();
#pragma weak __interrupt_189 = default_handler
__interrupt void __interrupt_190();
#pragma weak __interrupt_190 = default_handler
__interrupt void __interrupt_191();
#pragma weak __interrupt_191 = default_handler
__interrupt void __interrupt_192();
#pragma weak __interrupt_192 = default_handler
__interrupt void __interrupt_193();
#pragma weak __interrupt_193 = default_handler
__interrupt void __interrupt_194();
#pragma weak __interrupt_194 = default_handler
__interrupt void __interrupt_195();
#pragma weak __interrupt_195 = default_handler
__interrupt void __interrupt_196();
#pragma weak __interrupt_196 = default_handler
__interrupt void __interrupt_197();
#pragma weak __interrupt_197 = default_handler
__interrupt void __interrupt_198();
#pragma weak __interrupt_198 = default_handler
__interrupt void __interrupt_199();
#pragma weak __interrupt_199 = default_handler
__interrupt void __interrupt_200();
#pragma weak __interrupt_200 = default_handler
__interrupt void __interrupt_201();
#pragma weak __interrupt_201 = default_handler
__interrupt void __interrupt_202();
#pragma weak __interrupt_202 = default_handler
__interrupt void __interrupt_203();
#pragma weak __interrupt_203 = default_handler
__interrupt void __interrupt_204();
#pragma weak __interrupt_204 = default_handler
__interrupt void __interrupt_205();
#pragma weak __interrupt_205 = default_handler
__interrupt void __interrupt_206();
#pragma weak __interrupt_206 = default_handler
__interrupt void __interrupt_207();
#pragma weak __interrupt_207 = default_handler
__interrupt void __interrupt_208();
#pragma weak __interrupt_208 = default_handler
__interrupt void __interrupt_209();
#pragma weak __interrupt_209 = default_handler
__interrupt void __interrupt_210();
#pragma weak __interrupt_210 = default_handler
__interrupt void __interrupt_211();
#pragma weak __interrupt_211 = default_handler
__interrupt void __interrupt_212();
#pragma weak __interrupt_212 = default_handler
__interrupt void __interrupt_213();
#pragma weak __interrupt_213 = default_handler
__interrupt void __interrupt_214();
#pragma weak __interrupt_214 = default_handler
__interrupt void __interrupt_215();
#pragma weak __interrupt_215 = default_handler
__interrupt void __interrupt_216();
#pragma weak __interrupt_216 = default_handler
__interrupt void __interrupt_217();
#pragma weak __interrupt_217 = default_handler
__interrupt void __interrupt_218();
#pragma weak __interrupt_218 = default_handler
__interrupt void __interrupt_219();
#pragma weak __interrupt_219 = default_handler
__interrupt void __interrupt_220();
#pragma weak __interrupt_220 = default_handler
__interrupt void __interrupt_221();
#pragma weak __interrupt_221 = default_handler
__interrupt void __interrupt_222();
#pragma weak __interrupt_222 = default_handler
__interrupt void __interrupt_223();
#pragma weak __interrupt_223 = default_handler
__interrupt void __interrupt_224();
#pragma weak __interrupt_224 = default_handler
__interrupt void __interrupt_225();
#pragma weak __interrupt_225 = default_handler
__interrupt void __interrupt_226();
#pragma weak __interrupt_226 = default_handler
__interrupt void __interrupt_227();
#pragma weak __interrupt_227 = default_handler
__interrupt void __interrupt_228();
#pragma weak __interrupt_228 = default_handler
__interrupt void __interrupt_229();
#pragma weak __interrupt_229 = default_handler
__interrupt void __interrupt_230();
#pragma weak __interrupt_230 = default_handler
__interrupt void __interrupt_231();
#pragma weak __interrupt_231 = default_handler
__interrupt void __interrupt_232();
#pragma weak __interrupt_232 = default_handler
__interrupt void __interrupt_233();
#pragma weak __interrupt_233 = default_handler
__interrupt void __interrupt_234();
#pragma weak __interrupt_234 = default_handler
__interrupt void __interrupt_235();
#pragma weak __interrupt_235 = default_handler
__interrupt void __interrupt_236();
#pragma weak __interrupt_236 = default_handler
__interrupt void __interrupt_237();
#pragma weak __interrupt_237 = default_handler
__interrupt void __interrupt_238();
#pragma weak __interrupt_238 = default_handler
__interrupt void __interrupt_239();
#pragma weak __interrupt_239 = default_handler
__interrupt void __interrupt_240();
#pragma weak __interrupt_240 = default_handler
__interrupt void __interrupt_241();
#pragma weak __interrupt_241 = default_handler
__interrupt void __interrupt_242();
#pragma weak __interrupt_242 = default_handler
__interrupt void __interrupt_243();
#pragma weak __interrupt_243 = default_handler
__interrupt void __interrupt_244();
#pragma weak __interrupt_244 = default_handler
__interrupt void __interrupt_245();
#pragma weak __interrupt_245 = default_handler
__interrupt void __interrupt_246();
#pragma weak __interrupt_246 = default_handler
__interrupt void __interrupt_247();
#pragma weak __interrupt_247 = default_handler
__interrupt void __interrupt_248();
#pragma weak __interrupt_248 = default_handler
__interrupt void __interrupt_249();
#pragma weak __interrupt_249 = default_handler
__interrupt void __interrupt_250();
#pragma weak __interrupt_250 = default_handler
__interrupt void __interrupt_251();
#pragma weak __interrupt_251 = default_handler
__interrupt void __interrupt_252();
#pragma weak __interrupt_252 = default_handler
__interrupt void __interrupt_253();
#pragma weak __interrupt_253 = default_handler
__interrupt void __interrupt_254();
#pragma weak __interrupt_254 = default_handler
__interrupt void __interrupt_255();
#pragma weak __interrupt_255 = default_handler
__interrupt void __interrupt_256();

#if __ROPI__==1
#pragma location = ".inttable"
__root __fp vector_table[];
#else
#pragma location = ".inttable"
const __root __fp vector_table[] =
{
/*   0 */ __interrupt_0,
/*   1 */ (__fp)OSCtxSw,
/*   2 */ __interrupt_2,
/*   3 */ __interrupt_3,
/*   4 */ __interrupt_4,
/*   5 */ __interrupt_5,
/*   6 */ __interrupt_6,
/*   7 */ __interrupt_7,
/*   8 */ __interrupt_8,
/*   9 */ __interrupt_9,
/*  10 */ __interrupt_10,
/*  11 */ __interrupt_11,
/*  12 */ __interrupt_12,
/*  13 */ __interrupt_13,
/*  14 */ __interrupt_14,
/*  15 */ __interrupt_15,
/*  16 */ __interrupt_16,
/*  17 */ __interrupt_17,
/*  18 */ __interrupt_18,
/*  19 */ __interrupt_19,
/*  20 */ __interrupt_20,
/*  21 */ __interrupt_21,
/*  22 */ __interrupt_22,
/*  23 */ __interrupt_23,
/*  24 */ __interrupt_24,
/*  25 */ __interrupt_25,
/*  26 */ __interrupt_26,
/*  27 */ __interrupt_27,
/*  28 */ (__fp)OSTickISR,
/*  29 */ __interrupt_29,
/*  30 */ __interrupt_30,
/*  31 */ __interrupt_31,
/*  32 */ __interrupt_32,
/*  33 */ __interrupt_33,
/*  34 */ __interrupt_34,
/*  35 */ __interrupt_35,
/*  36 */ __interrupt_36,
/*  37 */ __interrupt_37,
/*  38 */ __interrupt_38,
/*  39 */ __interrupt_39,
/*  40 */ __interrupt_40,
/*  41 */ __interrupt_41,
/*  42 */ __interrupt_42,
/*  43 */ __interrupt_43,
/*  44 */ __interrupt_44,
/*  45 */ __interrupt_45,
/*  46 */ __interrupt_46,
/*  47 */ __interrupt_47,
/*  48 */ __interrupt_48,
/*  49 */ __interrupt_49,
/*  50 */ __interrupt_50,
/*  51 */ __interrupt_51,
/*  52 */ __interrupt_52,
/*  53 */ __interrupt_53,
/*  54 */ __interrupt_54,
/*  55 */ __interrupt_55,
/*  56 */ __interrupt_56,
/*  57 */ __interrupt_57,
/*  58 */ __interrupt_58,
/*  59 */ __interrupt_59,
/*  60 */ __interrupt_60,
/*  61 */ __interrupt_61,
/*  62 */ __interrupt_62,
/*  63 */ __interrupt_63,
/*  64 */ __interrupt_64,
/*  65 */ __interrupt_65,
/*  66 */ __interrupt_66,
/*  67 */ __interrupt_67,
/*  68 */ __interrupt_68,
/*  69 */ __interrupt_69,
/*  70 */ __interrupt_70,
/*  71 */ __interrupt_71,
/*  72 */ __interrupt_72,
/*  73 */ __interrupt_73,
/*  74 */ __interrupt_74,
/*  75 */ __interrupt_75,
/*  76 */ __interrupt_76,
/*  77 */ __interrupt_77,
/*  78 */ __interrupt_78,
/*  79 */ __interrupt_79,
/*  80 */ __interrupt_80,
/*  81 */ __interrupt_81,
/*  82 */ __interrupt_82,
/*  83 */ __interrupt_83,
/*  84 */ __interrupt_84,
/*  85 */ __interrupt_85,
/*  86 */ __interrupt_86,
/*  87 */ __interrupt_87,
/*  88 */ __interrupt_88,
/*  89 */ __interrupt_89,
/*  90 */ __interrupt_90,
/*  91 */ __interrupt_91,
/*  92 */ __interrupt_92,
/*  93 */ __interrupt_93,
/*  94 */ __interrupt_94,
/*  95 */ __interrupt_95,
/*  96 */ __interrupt_96,
/*  97 */ __interrupt_97,
/*  98 */ __interrupt_98,
/*  99 */ __interrupt_99,
/* 100 */ __interrupt_100,
/* 101 */ __interrupt_101,
/* 102 */ (__fp)AdcIsr,
/* 103 */ __interrupt_103,
/* 104 */ __interrupt_104,
/* 105 */ __interrupt_105,
/* 106 */ __interrupt_106,
/* 107 */ __interrupt_107,
/* 108 */ __interrupt_108,
/* 109 */ __interrupt_109,
/* 110 */ __interrupt_110,
/* 111 */ __interrupt_111,
/* 112 */ __interrupt_112,
/* 113 */ __interrupt_113,
/* 114 */ __interrupt_114,
/* 115 */ __interrupt_115,
/* 116 */ __interrupt_116,
/* 117 */ __interrupt_117,
/* 118 */ __interrupt_118,
/* 119 */ __interrupt_119,
/* 120 */ __interrupt_120,
/* 121 */ __interrupt_121,
/* 122 */ __interrupt_122,
/* 123 */ __interrupt_123,
/* 124 */ __interrupt_124,
/* 125 */ __interrupt_125,
/* 126 */ __interrupt_126,
/* 127 */ __interrupt_127,
/* 128 */ __interrupt_128,
/* 129 */ __interrupt_129,
/* 130 */ __interrupt_130,
/* 131 */ __interrupt_131,
/* 132 */ __interrupt_132,
/* 133 */ __interrupt_133,
/* 134 */ __interrupt_134,
/* 135 */ __interrupt_135,
/* 136 */ __interrupt_136,
/* 137 */ __interrupt_137,
/* 138 */ __interrupt_138,
/* 139 */ __interrupt_139,
/* 140 */ __interrupt_140,
/* 141 */ __interrupt_141,
/* 142 */ __interrupt_142,
/* 143 */ __interrupt_143,
/* 144 */ __interrupt_144,
/* 145 */ __interrupt_145,
/* 146 */ __interrupt_146,
/* 147 */ __interrupt_147,
/* 148 */ __interrupt_148,
/* 149 */ __interrupt_149,
/* 150 */ __interrupt_150,
/* 151 */ __interrupt_151,
/* 152 */ __interrupt_152,
/* 153 */ __interrupt_153,
/* 154 */ __interrupt_154,
/* 155 */ __interrupt_155,
/* 156 */ __interrupt_156,
/* 157 */ __interrupt_157,
/* 158 */ __interrupt_158,
/* 159 */ __interrupt_159,
/* 160 */ __interrupt_160,
/* 161 */ __interrupt_161,
/* 162 */ __interrupt_162,
/* 163 */ __interrupt_163,
/* 164 */ __interrupt_164,
/* 165 */ __interrupt_165,
/* 166 */ __interrupt_166,
/* 167 */ __interrupt_167,
/* 168 */ __interrupt_168,
/* 169 */ __interrupt_169,
/* 170 */ __interrupt_170,
/* 171 */ __interrupt_171,
/* 172 */ __interrupt_172,
/* 173 */ __interrupt_173,
/* 174 */ __interrupt_174,
/* 175 */ __interrupt_175,
/* 176 */ __interrupt_176,
/* 177 */ __interrupt_177,
/* 178 */ __interrupt_178,
/* 179 */ __interrupt_179,
/* 180 */ __interrupt_180,
/* 181 */ __interrupt_181,
/* 182 */ __interrupt_182,
/* 183 */ __interrupt_183,
/* 184 */ __interrupt_184,
/* 185 */ __interrupt_185,
/* 186 */ __interrupt_186,
/* 187 */ __interrupt_187,
/* 188 */ __interrupt_188,
/* 189 */ __interrupt_189,
/* 190 */ __interrupt_190,
/* 191 */ __interrupt_191,
/* 192 */ __interrupt_192,
/* 193 */ __interrupt_193,
/* 194 */ __interrupt_194,
/* 195 */ __interrupt_195,
/* 196 */ __interrupt_196,
/* 197 */ __interrupt_197,
/* 198 */ __interrupt_198,
/* 199 */ __interrupt_199,
/* 200 */ __interrupt_200,
/* 201 */ __interrupt_201,
/* 202 */ __interrupt_202,
/* 203 */ __interrupt_203,
/* 204 */ __interrupt_204,
/* 205 */ __interrupt_205,
/* 206 */ __interrupt_206,
/* 207 */ __interrupt_207,
/* 208 */ __interrupt_208,
/* 209 */ __interrupt_209,
/* 210 */ __interrupt_210,
/* 211 */ __interrupt_211,
/* 212 */ __interrupt_212,
/* 213 */ __interrupt_213,
/* 214 */ __interrupt_214,
/* 215 */ __interrupt_215,
/* 216 */ __interrupt_216,
/* 217 */ __interrupt_217,
/* 218 */ __interrupt_218,
/* 219 */ __interrupt_219,
/* 220 */ __interrupt_220,
/* 221 */ __interrupt_221,
/* 222 */ __interrupt_222,
/* 223 */ __interrupt_223,
/* 224 */ __interrupt_224,
/* 225 */ __interrupt_225,
/* 226 */ __interrupt_226,
/* 227 */ __interrupt_227,
/* 228 */ __interrupt_228,
/* 229 */ __interrupt_229,
/* 230 */ __interrupt_230,
/* 231 */ __interrupt_231,
/* 232 */ __interrupt_232,
/* 233 */ __interrupt_233,
/* 234 */ __interrupt_234,
/* 235 */ __interrupt_235,
/* 236 */ __interrupt_236,
/* 237 */ __interrupt_237,
/* 238 */ __interrupt_238,
/* 239 */ __interrupt_239,
/* 240 */ __interrupt_240,
/* 241 */ __interrupt_241,
/* 242 */ __interrupt_242,
/* 243 */ __interrupt_243,
/* 244 */ __interrupt_244,
/* 245 */ __interrupt_245,
/* 246 */ __interrupt_246,
/* 247 */ __interrupt_247,
/* 248 */ __interrupt_248,
/* 249 */ __interrupt_249,
/* 250 */ __interrupt_250,
/* 251 */ __interrupt_251,
/* 252 */ __interrupt_252,
/* 253 */ __interrupt_253,
/* 254 */ __interrupt_254,
/* 255 */ __interrupt_255,
};
#endif /* ROPI */
#pragma language=default
