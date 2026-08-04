#include "constants/battle.h"
#include "constants/pokemon.h"

#define X UQ_4_12
#define ______ X(1.0) // Regular effectiveness.

// Type matchup updates.                                                Attacker      Defender
#define STL_RS (B_UPDATED_TYPE_MATCHUPS >= GEN_6 ? X(1.0) : X(0.5))  // Ghost/Dark -> Steel
#define PSN_RS (B_UPDATED_TYPE_MATCHUPS >= GEN_2 ? X(0.5) : X(2.0))  // Bug        -> Poison
#define BUG_RS (B_UPDATED_TYPE_MATCHUPS >= GEN_2 ? X(1.0) : X(2.0))  // Poison     -> Bug
#define PSY_RS (B_UPDATED_TYPE_MATCHUPS >= GEN_2 ? X(2.0) : X(0.0))  // Ghost      -> Psychic
#define FIR_RS (B_UPDATED_TYPE_MATCHUPS >= GEN_2 ? X(0.5) : X(1.0))  // Ice        -> Fire

const uq4_12_t gTypeEffectivenessTable[NUMBER_OF_MON_TYPES][NUMBER_OF_MON_TYPES] =
{//                   Defender -->
 //  Attacker           None   Normal Fighting Flying  Poison  Ground   Rock    Bug     Ghost   Steel  Mystery  Fire   Water   Grass  Electric Psychic   Ice   Dragon   Dark   Fairy  Shadow  Light  Chaos  Angel  Demon  Aurum Crystal
    [TYPE_NONE]     = {______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_NORMAL]   = {______, ______, ______, ______, ______, ______, X(0.5), ______, X(0.0), X(0.5), ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_FIGHTING] = {______, X(2.0), ______, X(0.5), X(0.5), ______, X(2.0), X(0.5), X(0.0), X(2.0), ______, ______, ______, ______, ______, X(0.5), X(2.0), ______, X(2.0), X(0.5), ______, ______, ______, ______, ______, ______, ______},
    [TYPE_FLYING]   = {______, ______, X(2.0), ______, ______, ______, X(0.5), X(2.0), ______, X(0.5), ______, ______, ______, X(2.0), X(0.5), ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_POISON]   = {______, ______, ______, ______, X(0.5), X(0.5), X(0.5), BUG_RS, X(0.5), X(0.0), ______, ______, ______, X(2.0), ______, ______, ______, ______, ______, X(2.0), ______, ______, ______, ______, ______, ______, ______},
    [TYPE_GROUND]   = {______, ______, ______, X(0.0), X(2.0), ______, X(2.0), X(0.5), ______, X(2.0), ______, X(2.0), ______, X(0.5), X(2.0), ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_ROCK]     = {______, ______, X(0.5), X(2.0), ______, X(0.5), ______, X(2.0), ______, X(0.5), ______, X(2.0), ______, ______, ______, ______, X(2.0), ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_BUG]      = {______, ______, X(0.5), X(0.5), PSN_RS, ______, ______, ______, X(0.5), X(0.5), ______, X(0.5), ______, X(2.0), ______, X(2.0), ______, ______, X(2.0), X(0.5), ______, ______, ______, ______, ______, ______, ______},
    [TYPE_GHOST]    = {______, X(0.0), ______, ______, ______, ______, ______, ______, X(2.0), STL_RS, ______, ______, ______, ______, ______, PSY_RS, ______, ______, X(0.5), ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_STEEL]    = {______, ______, ______, ______, ______, ______, X(2.0), ______, ______, X(0.5), ______, X(0.5), X(0.5), ______, X(0.5), ______, X(2.0), ______, ______, X(2.0), ______, ______, ______, ______, ______, ______, ______},
    [TYPE_MYSTERY]  = {______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_FIRE]     = {______, ______, ______, ______, ______, ______, X(0.5), X(2.0), ______, X(2.0), ______, X(0.5), X(0.5), X(2.0), ______, ______, X(2.0), X(0.5), ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_WATER]    = {______, ______, ______, ______, ______, X(2.0), X(2.0), ______, ______, ______, ______, X(2.0), X(0.5), X(0.5), ______, ______, ______, X(0.5), ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_GRASS]    = {______, ______, ______, X(0.5), X(0.5), X(2.0), X(2.0), X(0.5), ______, X(0.5), ______, X(0.5), X(2.0), X(0.5), ______, ______, ______, X(0.5), ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_ELECTRIC] = {______, ______, ______, X(2.0), ______, X(0.0), ______, ______, ______, ______, ______, ______, X(2.0), X(0.5), X(0.5), ______, ______, X(0.5), ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_PSYCHIC]  = {______, ______, X(2.0), ______, X(2.0), ______, ______, ______, ______, X(0.5), ______, ______, ______, ______, ______, X(0.5), ______, ______, X(0.0), ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_ICE]      = {______, ______, ______, X(2.0), ______, X(2.0), ______, ______, ______, X(0.5), ______, FIR_RS, X(0.5), X(2.0), ______, ______, X(0.5), X(2.0), ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_DRAGON]   = {______, ______, ______, ______, ______, ______, ______, ______, ______, X(0.5), ______, ______, ______, ______, ______, ______, ______, X(2.0), ______, X(0.0), ______, ______, ______, ______, ______, ______, ______},
    [TYPE_DARK]     = {______, ______, X(0.5), ______, ______, ______, ______, ______, X(2.0), STL_RS, ______, ______, ______, ______, ______, X(2.0), ______, ______, X(0.5), X(0.5), ______, ______, ______, ______, ______, ______, ______},
    [TYPE_FAIRY]    = {______, ______, X(2.0), ______, X(0.5), ______, ______, ______, ______, X(0.5), ______, X(0.5), ______, ______, ______, ______, ______, X(2.0), X(2.0), ______, ______, ______, ______, ______, ______, ______, ______},
    // New types - temporary 1.0 (will be filled with real chart in Etapa 4)
    [TYPE_SHADOW]   = {______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_LIGHT]    = {______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_CHAOS]    = {______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_ANGEL]    = {______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_DEMON]    = {______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_AURUM]    = {______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
    [TYPE_CRYSTAL]  = {______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______},
};

#undef ______
#undef X

// Notes regarding custom data:
// - The "generic" field is large enough that the text for TYPE_ELECTRIC will exceed TEXT_BUFF_ARRAY_COUNT.
// - In this array there's commented-out data such as references to type-resist berries that would otherwise would go unused.
//   However, we figured this information would be useful for users that want to add their own types as a reminder of
//   what data would they need to add in order to have their new types be fully fledged like official types.
// - Changing "isHiddenPowerType" for any type will change the distribution of all Hidden Power types from vanilla.
const struct TypeInfo gTypesInfo[NUMBER_OF_MON_TYPES] =
{
    [TYPE_NONE] =
    {
        .name = _("None"),
        .generic = _("a move"),
        .palette = 15, // Uses TYPE_MYSTERY's icon
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB_WHITE,
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_NormalTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = TRUE,
        .isHiddenPowerType = FALSE,
    },
    [TYPE_NORMAL] =
    {
        .name = _("Normal"),
        .generic = _("a NORMAL move"),
        .palette = 13,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB_WHITE, // custom
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_NormalTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },
    [TYPE_FIGHTING] =
    {
        .name = _("Fighting"),
        .generic = _("a FIGHTING move"),
        .palette = 13,
        .zMove = MOVE_ALL_OUT_PUMMELING,
        .maxMove = MOVE_MAX_KNUCKLE,
        .teraTypeRGBValue = RGB(26, 8, 14),
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_FightingTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_FLYING] =
    {
        .name = _("Flying"),
        .generic = _("a FLYING move"),
        .palette = 14,
        .zMove = MOVE_SUPERSONIC_SKYSTRIKE,
        .maxMove = MOVE_MAX_AIRSTREAM,
        .teraTypeRGBValue = RGB(31, 26, 7),
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_FlyingTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_POISON] =
    {
        .name = _("Poison"),
        .generic = _("a POISON move"),
        .palette = 14,
        .zMove = MOVE_ACID_DOWNPOUR,
        .maxMove = MOVE_MAX_OOZE,
        .teraTypeRGBValue = RGB(26, 10, 25),
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_PoisonTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_GROUND] =
    {
        .name = _("Ground"),
        .generic = _("a GROUND move"),
        .palette = 13,
        .zMove = MOVE_TECTONIC_RAGE,
        .maxMove = MOVE_MAX_QUAKE,
        .teraTypeRGBValue = RGB(25, 23, 18),
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_GroundTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_ROCK] =
    {
        .name = _("Rock"),
        .generic = _("a ROCK move"),
        .palette = 13,
        .zMove = MOVE_CONTINENTAL_CRUSH,
        .maxMove = MOVE_MAX_ROCKFALL,
        .teraTypeRGBValue = RGB(18, 16, 8),
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_RockTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_BUG] =
    {
        .name = _("Bug"),
        .generic = _("a BUG move"),
        .palette = 15,
        .zMove = MOVE_SAVAGE_SPIN_OUT,
        .maxMove = MOVE_MAX_FLUTTERBY,
        .teraTypeRGBValue = RGB(18, 24, 6),
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_BugTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_GHOST] =
    {
        .name = _("Ghost"),
        .generic = _("a GHOST move"),
        .palette = 14,
        .zMove = MOVE_NEVER_ENDING_NIGHTMARE,
        .maxMove = MOVE_MAX_PHANTASM,
        .teraTypeRGBValue = RGB(12, 10, 16),
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_GhostTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_STEEL] =
    {
        .name = _("Steel"),
        .generic = _("a STEEL move"),
        .palette = 13,
        .zMove = MOVE_CORKSCREW_CRASH,
        .maxMove = MOVE_MAX_STEELSPIKE,
        .teraTypeRGBValue = RGB(19, 19, 20),
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_SteelTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_MYSTERY] =
    {
        .name = _("???"),
        .generic = _("a ??? move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ,
        .maxMove = MOVE_MAX_STRIKE,
        .teraTypeRGBValue = RGB_WHITE,
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_MysteryTMHM,
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = TRUE,
        .isHiddenPowerType = FALSE,
    },
    [TYPE_FIRE] =
    {
        .name = _("Fire"),
        .generic = _("a FIRE move"),
        .palette = 13,
        .zMove = MOVE_INFERNO_OVERDRIVE,
        .maxMove = MOVE_MAX_FLARE,
        .teraTypeRGBValue = RGB(31, 20, 11),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_FireTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_WATER] =
    {
        .name = _("Water"),
        .generic = _("a WATER move"),
        .palette = 14,
        .zMove = MOVE_HYDRO_VORTEX,
        .maxMove = MOVE_MAX_GEYSER,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_WaterTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_GRASS] =
    {
        .name = _("Grass"),
        .generic = _("a GRASS move"),
        .palette = 15,
        .zMove = MOVE_BLOOM_DOOM,
        .maxMove = MOVE_MAX_OVERGROWTH,
        .teraTypeRGBValue = RGB(12, 24, 11),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_GrassTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_ELECTRIC] =
    {
        .name = _("Electric"),
        .generic = _("an ELECTRIC move"),
        .palette = 13,
        .zMove = MOVE_GIGAVOLT_HAVOC,
        .maxMove = MOVE_MAX_LIGHTNING,
        .teraTypeRGBValue = RGB(30, 26, 7),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_ElectricTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_PSYCHIC] =
    {
        .name = _("Psychic"),
        .generic = _("a PSYCHIC move"),
        .palette = 14,
        .zMove = MOVE_SHATTERED_PSYCHE,
        .maxMove = MOVE_MAX_MINDSTORM,
        .teraTypeRGBValue = RGB(31, 14, 15),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_PsychicTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_ICE] =
    {
        .name = _("Ice"),
        .generic = _("an ICE move"),
        .palette = 14,
        .zMove = MOVE_SUBZERO_SLAMMER,
        .maxMove = MOVE_MAX_HAILSTORM,
        .teraTypeRGBValue = RGB(14, 26, 25),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_IceTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_DRAGON] =
    {
        .name = _("Dragon"),
        .generic = _("a DRAGON move"),
        .palette = 15,
        .zMove = MOVE_DEVASTATING_DRAKE,
        .maxMove = MOVE_MAX_WYRMWIND,
        .teraTypeRGBValue = RGB(10, 18, 27),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_DragonTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_DARK] =
    {
        .name = _("Dark"),
        .generic = _("a DARK move"),
        .palette = 13,
        .zMove = MOVE_BLACK_HOLE_ECLIPSE,
        .maxMove = MOVE_MAX_DARKNESS,
        .teraTypeRGBValue = RGB(6, 5, 8),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_DarkTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = TRUE,
    },
    [TYPE_FAIRY] =
    {
        .name = _("Fairy"),
        .generic = _("a FAIRY move"),
        .palette = 14,
        .zMove = MOVE_TWINKLE_TACKLE,
        .maxMove = MOVE_MAX_STARFALL,
        .teraTypeRGBValue = RGB(31, 15, 21),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_FairyTMHM,
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },
    // ========== NEW TYPES ==========
    [TYPE_SHADOW] =
    {
        .name = _("Shadow"),
        .generic = _("a SHADOW move"),
        .palette = 13,
        .zMove = MOVE_BLACK_HOLE_ECLIPSE, // temporary
        .maxMove = MOVE_MAX_DARKNESS,    // temporary
        .teraTypeRGBValue = RGB(8, 4, 12),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_DarkTMHM, // temporary
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },
    [TYPE_LIGHT] =
    {
        .name = _("Light"),
        .generic = _("a LIGHT move"),
        .palette = 14,
        .zMove = MOVE_TWINKLE_TACKLE, // temporary
        .maxMove = MOVE_MAX_STARFALL, // temporary
        .teraTypeRGBValue = RGB(31, 31, 20),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_FairyTMHM, // temporary
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },
    [TYPE_CHAOS] =
    {
        .name = _("Chaos"),
        .generic = _("a CHAOS move"),
        .palette = 15,
        .zMove = MOVE_BREAKNECK_BLITZ, // temporary
        .maxMove = MOVE_MAX_STRIKE,    // temporary
        .teraTypeRGBValue = RGB(20, 8, 24),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_PsychicTMHM, // temporary
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },
    [TYPE_ANGEL] =
    {
        .name = _("Angel"),
        .generic = _("an ANGEL move"),
        .palette = 14,
        .zMove = MOVE_TWINKLE_TACKLE, // temporary
        .maxMove = MOVE_MAX_STARFALL, // temporary
        .teraTypeRGBValue = RGB(28, 28, 31),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_FairyTMHM, // temporary
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },
    [TYPE_DEMON] =
    {
        .name = _("Demon"),
        .generic = _("a DEMON move"),
        .palette = 13,
        .zMove = MOVE_BLACK_HOLE_ECLIPSE, // temporary
        .maxMove = MOVE_MAX_DARKNESS,    // temporary
        .teraTypeRGBValue = RGB(18, 4, 8),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_DarkTMHM, // temporary
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },
    [TYPE_AURUM] =
    {
        .name = _("Aurum"),
        .generic = _("an AURUM move"),
        .palette = 13,
        .zMove = MOVE_CORKSCREW_CRASH, // temporary
        .maxMove = MOVE_MAX_STEELSPIKE, // temporary
        .teraTypeRGBValue = RGB(28, 24, 8),
        .damageCategory = DAMAGE_CATEGORY_PHYSICAL,
        .paletteTMHM = gItemIconPalette_SteelTMHM, // temporary
        .useSecondTypeIconPalette = FALSE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },
    [TYPE_CRYSTAL] =
    {
        .name = _("Crystal"),
        .generic = _("a CRYSTAL move"),
        .palette = 14,
        .zMove = MOVE_BREAKNECK_BLITZ, // temporary
        .maxMove = MOVE_MAX_STRIKE,    // temporary
        .teraTypeRGBValue = RGB(20, 28, 31),
        .damageCategory = DAMAGE_CATEGORY_SPECIAL,
        .paletteTMHM = gItemIconPalette_IceTMHM, // temporary
        .useSecondTypeIconPalette = TRUE,
        .isSpecialCaseType = FALSE,
        .isHiddenPowerType = FALSE,
    },
};
