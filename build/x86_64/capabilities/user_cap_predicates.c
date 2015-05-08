#include <barrelfish/barrelfish.h>
#include <barrelfish_kpi/capbits.h>
#include <barrelfish/cap_predicates.h>
/* Includes: */
 
#include <stdint.h>
#include <assert.h>
 
/* Function Definitions: */
 
int8_t compare_caps(struct  capability* left,struct  capability* right,bool tiebreak) {
    uint8_t _fof_x127;
    uint8_t _fof_x128;
    genpaddr_t _fof_x129;
    genpaddr_t _fof_x130;
    gensize_t _fof_x131;
    gensize_t _fof_x132;
    struct  capability* left__121;
    struct  capability left__121__122;
    enum objtype left__121__122__125;
    union  capability_u left__121__122__133;
    struct  FCNode left__121__122__133__135;
    genpaddr_t left__121__122__133__135__137;
    uint8_t left__121__122__133__135__139;
    coreid_t left__121__122__133__135__141;
    union  capability_u left__121__122__143;
    struct  IO left__121__122__143__145;
    uint16_t left__121__122__143__145__147;
    uint16_t left__121__122__143__145__149;
    union  capability_u left__121__122__151;
    struct  Notify_RCK left__121__122__151__153;
    coreid_t left__121__122__151__153__155;
    uint16_t left__121__122__151__153__157;
    union  capability_u left__121__122__159;
    struct  Notify_IPI left__121__122__159__161;
    coreid_t left__121__122__159__161__163;
    uint16_t left__121__122__159__161__165;
    union  capability_u left__121__122__167;
    struct  ID left__121__122__167__169;
    coreid_t left__121__122__167__169__171;
    uint32_t left__121__122__167__169__173;
    struct  capability* right__123;
    struct  capability right__123__124;
    enum objtype right__123__124__126;
    union  capability_u right__123__124__134;
    struct  FCNode right__123__124__134__136;
    genpaddr_t right__123__124__134__136__138;
    uint8_t right__123__124__134__136__140;
    coreid_t right__123__124__134__136__142;
    union  capability_u right__123__124__144;
    struct  IO right__123__124__144__146;
    uint16_t right__123__124__144__146__148;
    uint16_t right__123__124__144__146__150;
    union  capability_u right__123__124__152;
    struct  Notify_RCK right__123__124__152__154;
    coreid_t right__123__124__152__154__156;
    uint16_t right__123__124__152__154__158;
    union  capability_u right__123__124__160;
    struct  Notify_IPI right__123__124__160__162;
    coreid_t right__123__124__160__162__164;
    uint16_t right__123__124__160__162__166;
    union  capability_u right__123__124__168;
    struct  ID right__123__124__168__170;
    coreid_t right__123__124__168__170__172;
    uint32_t right__123__124__168__170__174;
 
    left__121 = left;
    left__121__122 = *left__121;
    right__123 = right;
    right__123__124 = *right__123;
    left__121__122__125 = left__121__122.type;
    right__123__124__126 = right__123__124.type;
    _fof_x127 = get_type_root(left__121__122__125);
    _fof_x128 = get_type_root(right__123__124__126);
    if ((_fof_x127 != _fof_x128)){
        return ((((_fof_x127 < _fof_x128)) ? (-1) : (1)));
    } else {
    }
    _fof_x129 = get_address(left);
    _fof_x130 = get_address(right);
    if ((_fof_x129 != _fof_x130)){
        return ((((_fof_x129 < _fof_x130)) ? (-1) : (1)));
    } else {
    }
    _fof_x131 = get_size(left);
    _fof_x132 = get_size(right);
    if ((_fof_x131 != _fof_x132)){
        return ((((_fof_x131 > _fof_x132)) ? (-1) : (1)));
    } else {
    }
    if ((left__121__122__125 != right__123__124__126)){
        return ((((left__121__122__125 < right__123__124__126)) ? (-1) : (1)));
    } else {
    }
    switch (left__121__122__125) {
        case ObjType_ID: {
            left__121__122__167 = left__121__122.u;
            right__123__124__168 = right__123__124.u;
            left__121__122__167__169 = left__121__122__167.id;
            right__123__124__168__170 = right__123__124__168.id;
            left__121__122__167__169__171 = left__121__122__167__169.coreid;
            right__123__124__168__170__172 = right__123__124__168__170.coreid;
            if ((left__121__122__167__169__171 != right__123__124__168__170__172)){
                return ((((left__121__122__167__169__171 < right__123__124__168__170__172)) ? (-1) : (1)));
            } else {
            }
            left__121__122__167__169__173 = left__121__122__167__169.core_local_id;
            right__123__124__168__170__174 = right__123__124__168__170.core_local_id;
            if ((left__121__122__167__169__173 != right__123__124__168__170__174)){
                return ((((left__121__122__167__169__173 < right__123__124__168__170__174)) ? (-1) : (1)));
            } else {
            }
            break;
        }
        case ObjType_Notify_IPI: {
            left__121__122__159 = left__121__122.u;
            right__123__124__160 = right__123__124.u;
            left__121__122__159__161 = left__121__122__159.notify_ipi;
            right__123__124__160__162 = right__123__124__160.notify_ipi;
            left__121__122__159__161__163 = left__121__122__159__161.coreid;
            right__123__124__160__162__164 = right__123__124__160__162.coreid;
            if ((left__121__122__159__161__163 != right__123__124__160__162__164)){
                return ((((left__121__122__159__161__163 < right__123__124__160__162__164)) ? (-1) : (1)));
            } else {
            }
            left__121__122__159__161__165 = left__121__122__159__161.chanid;
            right__123__124__160__162__166 = right__123__124__160__162.chanid;
            if ((left__121__122__159__161__165 != right__123__124__160__162__166)){
                return ((((left__121__122__159__161__165 < right__123__124__160__162__166)) ? (-1) : (1)));
            } else {
            }
            break;
        }
        case ObjType_Notify_RCK: {
            left__121__122__151 = left__121__122.u;
            right__123__124__152 = right__123__124.u;
            left__121__122__151__153 = left__121__122__151.notify_rck;
            right__123__124__152__154 = right__123__124__152.notify_rck;
            left__121__122__151__153__155 = left__121__122__151__153.coreid;
            right__123__124__152__154__156 = right__123__124__152__154.coreid;
            if ((left__121__122__151__153__155 != right__123__124__152__154__156)){
                return ((((left__121__122__151__153__155 < right__123__124__152__154__156)) ? (-1) : (1)));
            } else {
            }
            left__121__122__151__153__157 = left__121__122__151__153.chanid;
            right__123__124__152__154__158 = right__123__124__152__154.chanid;
            if ((left__121__122__151__153__157 != right__123__124__152__154__158)){
                return ((((left__121__122__151__153__157 < right__123__124__152__154__158)) ? (-1) : (1)));
            } else {
            }
            break;
        }
        case ObjType_IO: {
            left__121__122__143 = left__121__122.u;
            right__123__124__144 = right__123__124.u;
            left__121__122__143__145 = left__121__122__143.io;
            right__123__124__144__146 = right__123__124__144.io;
            left__121__122__143__145__147 = left__121__122__143__145.start;
            right__123__124__144__146__148 = right__123__124__144__146.start;
            if ((left__121__122__143__145__147 != right__123__124__144__146__148)){
                return ((((left__121__122__143__145__147 < right__123__124__144__146__148)) ? (-1) : (1)));
            } else {
            }
            left__121__122__143__145__149 = left__121__122__143__145.end;
            right__123__124__144__146__150 = right__123__124__144__146.end;
            if ((left__121__122__143__145__149 != right__123__124__144__146__150)){
                return ((((left__121__122__143__145__149 < right__123__124__144__146__150)) ? (-1) : (1)));
            } else {
            }
            break;
        }
        case ObjType_FCNode: {
            left__121__122__133 = left__121__122.u;
            right__123__124__134 = right__123__124.u;
            left__121__122__133__135 = left__121__122__133.fcnode;
            right__123__124__134__136 = right__123__124__134.fcnode;
            left__121__122__133__135__137 = left__121__122__133__135.cnode;
            right__123__124__134__136__138 = right__123__124__134__136.cnode;
            if ((left__121__122__133__135__137 != right__123__124__134__136__138)){
                return ((((left__121__122__133__135__137 < right__123__124__134__136__138)) ? (-1) : (1)));
            } else {
            }
            left__121__122__133__135__139 = left__121__122__133__135.bits;
            right__123__124__134__136__140 = right__123__124__134__136.bits;
            if ((left__121__122__133__135__139 != right__123__124__134__136__140)){
                return ((((left__121__122__133__135__139 < right__123__124__134__136__140)) ? (-1) : (1)));
            } else {
            }
            left__121__122__133__135__141 = left__121__122__133__135.core_id;
            right__123__124__134__136__142 = right__123__124__134__136.core_id;
            if ((left__121__122__133__135__141 != right__123__124__134__136__142)){
                return ((((left__121__122__133__135__141 < right__123__124__134__136__142)) ? (-1) : (1)));
            } else {
            }
            break;
        }
        default: {
        }
    }
    if (tiebreak){
        if ((left != right)){
            return ((((left < right)) ? (-1) : (1)));
        } else {
        }
    } else {
    }
    return (0);
}
 
genpaddr_t get_address(struct  capability* cap) {
    uint64_t _fof_x25;
    uint64_t _fof_x31;
    uint64_t _fof_x92;
    struct  capability* cap__10;
    struct  capability cap__10__11;
    union  capability_u cap__10__11__12;
    struct  RAM cap__10__11__12__13;
    genpaddr_t cap__10__11__12__13__14;
    struct  capability* cap__15;
    struct  capability cap__15__16;
    union  capability_u cap__15__16__17;
    struct  CNode cap__15__16__17__18;
    lpaddr_t cap__15__16__17__18__19;
    struct  capability* cap__2;
    struct  capability* cap__20;
    struct  capability cap__20__21;
    union  capability_u cap__20__21__22;
    struct  Dispatcher cap__20__21__22__23;
    struct dcb* cap__20__21__22__23__24;
    struct  capability* cap__26;
    struct  capability cap__26__27;
    union  capability_u cap__26__27__28;
    struct  EndPoint cap__26__27__28__29;
    struct dcb* cap__26__27__28__29__30;
    struct  capability cap__2__3;
    enum objtype cap__2__3__4;
    struct  capability* cap__32;
    struct  capability cap__32__33;
    union  capability_u cap__32__33__34;
    struct  Frame cap__32__33__34__35;
    genpaddr_t cap__32__33__34__35__36;
    struct  capability* cap__37;
    struct  capability cap__37__38;
    union  capability_u cap__37__38__39;
    struct  DevFrame cap__37__38__39__40;
    genpaddr_t cap__37__38__39__40__41;
    struct  capability* cap__42;
    struct  capability cap__42__43;
    union  capability_u cap__42__43__44;
    struct  VNode_x86_64_pml4 cap__42__43__44__45;
    genpaddr_t cap__42__43__44__45__46;
    struct  capability* cap__47;
    struct  capability cap__47__48;
    union  capability_u cap__47__48__49;
    struct  VNode_x86_64_pdpt cap__47__48__49__50;
    genpaddr_t cap__47__48__49__50__51;
    struct  capability* cap__5;
    struct  capability* cap__52;
    struct  capability cap__52__53;
    union  capability_u cap__52__53__54;
    struct  VNode_x86_64_pdir cap__52__53__54__55;
    genpaddr_t cap__52__53__54__55__56;
    struct  capability* cap__57;
    struct  capability cap__57__58;
    union  capability_u cap__57__58__59;
    struct  VNode_x86_64_ptable cap__57__58__59__60;
    genpaddr_t cap__57__58__59__60__61;
    struct  capability cap__5__6;
    union  capability_u cap__5__6__7;
    struct  PhysAddr cap__5__6__7__8;
    genpaddr_t cap__5__6__7__8__9;
    struct  capability* cap__62;
    struct  capability cap__62__63;
    union  capability_u cap__62__63__64;
    struct  VNode_x86_32_pdpt cap__62__63__64__65;
    genpaddr_t cap__62__63__64__65__66;
    struct  capability* cap__67;
    struct  capability cap__67__68;
    union  capability_u cap__67__68__69;
    struct  VNode_x86_32_pdir cap__67__68__69__70;
    genpaddr_t cap__67__68__69__70__71;
    struct  capability* cap__72;
    struct  capability cap__72__73;
    union  capability_u cap__72__73__74;
    struct  VNode_x86_32_ptable cap__72__73__74__75;
    genpaddr_t cap__72__73__74__75__76;
    struct  capability* cap__77;
    struct  capability cap__77__78;
    union  capability_u cap__77__78__79;
    struct  VNode_ARM_l1 cap__77__78__79__80;
    genpaddr_t cap__77__78__79__80__81;
    struct  capability* cap__82;
    struct  capability cap__82__83;
    union  capability_u cap__82__83__84;
    struct  VNode_ARM_l2 cap__82__83__84__85;
    genpaddr_t cap__82__83__84__85__86;
    struct  capability* cap__87;
    struct  capability cap__87__88;
    union  capability_u cap__87__88__89;
    struct  KernelControlBlock cap__87__88__89__90;
    struct kcb* cap__87__88__89__90__91;
 
    cap__2 = cap;
    cap__2__3 = *cap__2;
    cap__2__3__4 = cap__2__3.type;
    switch (cap__2__3__4) {
        case ObjType_IPI: {
            return (((genpaddr_t) 0));
            break;
        }
        case ObjType_KernelControlBlock: {
            cap__87 = cap;
            cap__87__88 = *cap__87;
            cap__87__88__89 = cap__87__88.u;
            cap__87__88__89__90 = cap__87__88__89.kernelcontrolblock;
            cap__87__88__89__90__91 = cap__87__88__89__90.kcb;
            _fof_x92 = mem_to_local_phys(((lvaddr_t) cap__87__88__89__90__91));
            return (_fof_x92);
            break;
        }
        case ObjType_PerfMon: {
            return (((genpaddr_t) 0));
            break;
        }
        case ObjType_ID: {
            return (((genpaddr_t) 0));
            break;
        }
        case ObjType_Notify_IPI: {
            return (((genpaddr_t) 0));
            break;
        }
        case ObjType_Notify_RCK: {
            return (((genpaddr_t) 0));
            break;
        }
        case ObjType_IO: {
            return (((genpaddr_t) 0));
            break;
        }
        case ObjType_IRQTable: {
            return (((genpaddr_t) 0));
            break;
        }
        case ObjType_VNode_ARM_l2: {
            cap__82 = cap;
            cap__82__83 = *cap__82;
            cap__82__83__84 = cap__82__83.u;
            cap__82__83__84__85 = cap__82__83__84.vnode_arm_l2;
            cap__82__83__84__85__86 = cap__82__83__84__85.base;
            return (cap__82__83__84__85__86);
            break;
        }
        case ObjType_VNode_ARM_l1: {
            cap__77 = cap;
            cap__77__78 = *cap__77;
            cap__77__78__79 = cap__77__78.u;
            cap__77__78__79__80 = cap__77__78__79.vnode_arm_l1;
            cap__77__78__79__80__81 = cap__77__78__79__80.base;
            return (cap__77__78__79__80__81);
            break;
        }
        case ObjType_VNode_x86_32_ptable: {
            cap__72 = cap;
            cap__72__73 = *cap__72;
            cap__72__73__74 = cap__72__73.u;
            cap__72__73__74__75 = cap__72__73__74.vnode_x86_32_ptable;
            cap__72__73__74__75__76 = cap__72__73__74__75.base;
            return (cap__72__73__74__75__76);
            break;
        }
        case ObjType_VNode_x86_32_pdir: {
            cap__67 = cap;
            cap__67__68 = *cap__67;
            cap__67__68__69 = cap__67__68.u;
            cap__67__68__69__70 = cap__67__68__69.vnode_x86_32_pdir;
            cap__67__68__69__70__71 = cap__67__68__69__70.base;
            return (cap__67__68__69__70__71);
            break;
        }
        case ObjType_VNode_x86_32_pdpt: {
            cap__62 = cap;
            cap__62__63 = *cap__62;
            cap__62__63__64 = cap__62__63.u;
            cap__62__63__64__65 = cap__62__63__64.vnode_x86_32_pdpt;
            cap__62__63__64__65__66 = cap__62__63__64__65.base;
            return (cap__62__63__64__65__66);
            break;
        }
        case ObjType_VNode_x86_64_ptable: {
            cap__57 = cap;
            cap__57__58 = *cap__57;
            cap__57__58__59 = cap__57__58.u;
            cap__57__58__59__60 = cap__57__58__59.vnode_x86_64_ptable;
            cap__57__58__59__60__61 = cap__57__58__59__60.base;
            return (cap__57__58__59__60__61);
            break;
        }
        case ObjType_VNode_x86_64_pdir: {
            cap__52 = cap;
            cap__52__53 = *cap__52;
            cap__52__53__54 = cap__52__53.u;
            cap__52__53__54__55 = cap__52__53__54.vnode_x86_64_pdir;
            cap__52__53__54__55__56 = cap__52__53__54__55.base;
            return (cap__52__53__54__55__56);
            break;
        }
        case ObjType_VNode_x86_64_pdpt: {
            cap__47 = cap;
            cap__47__48 = *cap__47;
            cap__47__48__49 = cap__47__48.u;
            cap__47__48__49__50 = cap__47__48__49.vnode_x86_64_pdpt;
            cap__47__48__49__50__51 = cap__47__48__49__50.base;
            return (cap__47__48__49__50__51);
            break;
        }
        case ObjType_VNode_x86_64_pml4: {
            cap__42 = cap;
            cap__42__43 = *cap__42;
            cap__42__43__44 = cap__42__43.u;
            cap__42__43__44__45 = cap__42__43__44.vnode_x86_64_pml4;
            cap__42__43__44__45__46 = cap__42__43__44__45.base;
            return (cap__42__43__44__45__46);
            break;
        }
        case ObjType_Kernel: {
            return (((genpaddr_t) 0));
            break;
        }
        case ObjType_DevFrame: {
            cap__37 = cap;
            cap__37__38 = *cap__37;
            cap__37__38__39 = cap__37__38.u;
            cap__37__38__39__40 = cap__37__38__39.devframe;
            cap__37__38__39__40__41 = cap__37__38__39__40.base;
            return (cap__37__38__39__40__41);
            break;
        }
        case ObjType_Frame: {
            cap__32 = cap;
            cap__32__33 = *cap__32;
            cap__32__33__34 = cap__32__33.u;
            cap__32__33__34__35 = cap__32__33__34.frame;
            cap__32__33__34__35__36 = cap__32__33__34__35.base;
            return (cap__32__33__34__35__36);
            break;
        }
        case ObjType_EndPoint: {
            cap__26 = cap;
            cap__26__27 = *cap__26;
            cap__26__27__28 = cap__26__27.u;
            cap__26__27__28__29 = cap__26__27__28.endpoint;
            cap__26__27__28__29__30 = cap__26__27__28__29.listener;
            _fof_x31 = mem_to_local_phys(((lvaddr_t) cap__26__27__28__29__30));
            return (_fof_x31);
            break;
        }
        case ObjType_Dispatcher: {
            cap__20 = cap;
            cap__20__21 = *cap__20;
            cap__20__21__22 = cap__20__21.u;
            cap__20__21__22__23 = cap__20__21__22.dispatcher;
            cap__20__21__22__23__24 = cap__20__21__22__23.dcb;
            _fof_x25 = mem_to_local_phys(((lvaddr_t) cap__20__21__22__23__24));
            return (_fof_x25);
            break;
        }
        case ObjType_FCNode: {
            return (((genpaddr_t) 0));
            break;
        }
        case ObjType_CNode: {
            cap__15 = cap;
            cap__15__16 = *cap__15;
            cap__15__16__17 = cap__15__16.u;
            cap__15__16__17__18 = cap__15__16__17.cnode;
            cap__15__16__17__18__19 = cap__15__16__17__18.cnode;
            return (cap__15__16__17__18__19);
            break;
        }
        case ObjType_RAM: {
            cap__10 = cap;
            cap__10__11 = *cap__10;
            cap__10__11__12 = cap__10__11.u;
            cap__10__11__12__13 = cap__10__11__12.ram;
            cap__10__11__12__13__14 = cap__10__11__12__13.base;
            return (cap__10__11__12__13__14);
            break;
        }
        case ObjType_PhysAddr: {
            cap__5 = cap;
            cap__5__6 = *cap__5;
            cap__5__6__7 = cap__5__6.u;
            cap__5__6__7__8 = cap__5__6__7.physaddr;
            cap__5__6__7__8__9 = cap__5__6__7__8.base;
            return (cap__5__6__7__8__9);
            break;
        }
        case ObjType_Null: {
            return (((genpaddr_t) 0));
            break;
        }
        default: {
            assert(0);
            return (0);
        }
    }
}
 
gensize_t get_size(struct  capability* cap) {
    struct  capability* cap__101;
    struct  capability cap__101__102;
    union  capability_u cap__101__102__103;
    struct  RAM cap__101__102__103__104;
    uint8_t cap__101__102__103__104__105;
    struct  capability* cap__106;
    struct  capability cap__106__107;
    union  capability_u cap__106__107__108;
    struct  CNode cap__106__107__108__109;
    uint8_t cap__106__107__108__109__110;
    struct  capability* cap__111;
    struct  capability cap__111__112;
    union  capability_u cap__111__112__113;
    struct  Frame cap__111__112__113__114;
    uint8_t cap__111__112__113__114__115;
    struct  capability* cap__116;
    struct  capability cap__116__117;
    union  capability_u cap__116__117__118;
    struct  DevFrame cap__116__117__118__119;
    uint8_t cap__116__117__118__119__120;
    struct  capability* cap__93;
    struct  capability cap__93__94;
    enum objtype cap__93__94__95;
    struct  capability* cap__96;
    struct  capability cap__96__97;
    union  capability_u cap__96__97__98;
    struct  PhysAddr cap__96__97__98__99;
    uint8_t cap__96__97__98__99__100;
 
    cap__93 = cap;
    cap__93__94 = *cap__93;
    cap__93__94__95 = cap__93__94.type;
    switch (cap__93__94__95) {
        case ObjType_IPI: {
            return (((gensize_t) 0));
            break;
        }
        case ObjType_KernelControlBlock: {
            return ((((gensize_t) 1) << 16));
            break;
        }
        case ObjType_PerfMon: {
            return (((gensize_t) 0));
            break;
        }
        case ObjType_ID: {
            return (((gensize_t) 0));
            break;
        }
        case ObjType_Notify_IPI: {
            return (((gensize_t) 0));
            break;
        }
        case ObjType_Notify_RCK: {
            return (((gensize_t) 0));
            break;
        }
        case ObjType_IO: {
            return (((gensize_t) 0));
            break;
        }
        case ObjType_IRQTable: {
            return (((gensize_t) 0));
            break;
        }
        case ObjType_VNode_ARM_l2: {
            return ((((gensize_t) 1) << 12));
            break;
        }
        case ObjType_VNode_ARM_l1: {
            return ((((gensize_t) 1) << 12));
            break;
        }
        case ObjType_VNode_x86_32_ptable: {
            return ((((gensize_t) 1) << 12));
            break;
        }
        case ObjType_VNode_x86_32_pdir: {
            return ((((gensize_t) 1) << 12));
            break;
        }
        case ObjType_VNode_x86_32_pdpt: {
            return ((((gensize_t) 1) << 12));
            break;
        }
        case ObjType_VNode_x86_64_ptable: {
            return ((((gensize_t) 1) << 12));
            break;
        }
        case ObjType_VNode_x86_64_pdir: {
            return ((((gensize_t) 1) << 12));
            break;
        }
        case ObjType_VNode_x86_64_pdpt: {
            return ((((gensize_t) 1) << 12));
            break;
        }
        case ObjType_VNode_x86_64_pml4: {
            return ((((gensize_t) 1) << 12));
            break;
        }
        case ObjType_Kernel: {
            return (((gensize_t) 0));
            break;
        }
        case ObjType_DevFrame: {
            cap__116 = cap;
            cap__116__117 = *cap__116;
            cap__116__117__118 = cap__116__117.u;
            cap__116__117__118__119 = cap__116__117__118.devframe;
            cap__116__117__118__119__120 = cap__116__117__118__119.bits;
            return ((((gensize_t) 1) << cap__116__117__118__119__120));
            break;
        }
        case ObjType_Frame: {
            cap__111 = cap;
            cap__111__112 = *cap__111;
            cap__111__112__113 = cap__111__112.u;
            cap__111__112__113__114 = cap__111__112__113.frame;
            cap__111__112__113__114__115 = cap__111__112__113__114.bits;
            return ((((gensize_t) 1) << cap__111__112__113__114__115));
            break;
        }
        case ObjType_EndPoint: {
            return (0);
            break;
        }
        case ObjType_Dispatcher: {
            return ((((gensize_t) 1) << 10));
            break;
        }
        case ObjType_FCNode: {
            return (((gensize_t) 0));
            break;
        }
        case ObjType_CNode: {
            cap__106 = cap;
            cap__106__107 = *cap__106;
            cap__106__107__108 = cap__106__107.u;
            cap__106__107__108__109 = cap__106__107__108.cnode;
            cap__106__107__108__109__110 = cap__106__107__108__109.bits;
            return ((((gensize_t) 1) << (cap__106__107__108__109__110 + 7)));
            break;
        }
        case ObjType_RAM: {
            cap__101 = cap;
            cap__101__102 = *cap__101;
            cap__101__102__103 = cap__101__102.u;
            cap__101__102__103__104 = cap__101__102__103.ram;
            cap__101__102__103__104__105 = cap__101__102__103__104.bits;
            return ((((gensize_t) 1) << cap__101__102__103__104__105));
            break;
        }
        case ObjType_PhysAddr: {
            cap__96 = cap;
            cap__96__97 = *cap__96;
            cap__96__97__98 = cap__96__97.u;
            cap__96__97__98__99 = cap__96__97__98.physaddr;
            cap__96__97__98__99__100 = cap__96__97__98__99.bits;
            return ((((gensize_t) 1) << cap__96__97__98__99__100));
            break;
        }
        case ObjType_Null: {
            return (((gensize_t) 0));
            break;
        }
        default: {
            assert(0);
            return (0);
        }
    }
}
 
uint8_t get_type_root(enum objtype type) {
 
    switch (type) {
        case ObjType_IPI: {
            return (10);
            break;
        }
        case ObjType_KernelControlBlock: {
            return (1);
            break;
        }
        case ObjType_PerfMon: {
            return (9);
            break;
        }
        case ObjType_ID: {
            return (8);
            break;
        }
        case ObjType_Notify_IPI: {
            return (7);
            break;
        }
        case ObjType_Notify_RCK: {
            return (6);
            break;
        }
        case ObjType_IO: {
            return (5);
            break;
        }
        case ObjType_IRQTable: {
            return (4);
            break;
        }
        case ObjType_VNode_ARM_l2: {
            return (1);
            break;
        }
        case ObjType_VNode_ARM_l1: {
            return (1);
            break;
        }
        case ObjType_VNode_x86_32_ptable: {
            return (1);
            break;
        }
        case ObjType_VNode_x86_32_pdir: {
            return (1);
            break;
        }
        case ObjType_VNode_x86_32_pdpt: {
            return (1);
            break;
        }
        case ObjType_VNode_x86_64_ptable: {
            return (1);
            break;
        }
        case ObjType_VNode_x86_64_pdir: {
            return (1);
            break;
        }
        case ObjType_VNode_x86_64_pdpt: {
            return (1);
            break;
        }
        case ObjType_VNode_x86_64_pml4: {
            return (1);
            break;
        }
        case ObjType_Kernel: {
            return (3);
            break;
        }
        case ObjType_DevFrame: {
            return (1);
            break;
        }
        case ObjType_Frame: {
            return (1);
            break;
        }
        case ObjType_EndPoint: {
            return (1);
            break;
        }
        case ObjType_Dispatcher: {
            return (1);
            break;
        }
        case ObjType_FCNode: {
            return (2);
            break;
        }
        case ObjType_CNode: {
            return (1);
            break;
        }
        case ObjType_RAM: {
            return (1);
            break;
        }
        case ObjType_PhysAddr: {
            return (1);
            break;
        }
        case ObjType_Null: {
            return (0);
            break;
        }
        default: {
            assert(0);
            return (0);
        }
    }
}
 
bool is_ancestor(struct  capability* child,struct  capability* parent) {
    bool _fof_x188;
    genpaddr_t _fof_x189;
    genpaddr_t _fof_x190;
    gensize_t _fof_x191;
    gensize_t _fof_x192;
    struct  capability* child__182;
    struct  capability child__182__183;
    enum objtype child__182__183__186;
    struct  capability* parent__184;
    struct  capability parent__184__185;
    enum objtype parent__184__185__187;
 
    child__182 = child;
    child__182__183 = *child__182;
    parent__184 = parent;
    parent__184__185 = *parent__184;
    child__182__183__186 = child__182__183.type;
    parent__184__185__187 = parent__184__185.type;
    _fof_x188 = is_well_founded(parent__184__185__187,child__182__183__186);
    if ((! _fof_x188)){
        return (0);
    } else {
    }
    _fof_x189 = get_address(parent);
    _fof_x190 = get_address(child);
    _fof_x191 = get_size(parent);
    _fof_x192 = get_size(child);
    if ((child__182__183__186 == parent__184__185__187)){
        return ((((_fof_x189 < _fof_x190) & ((_fof_x189 + _fof_x191) >= (_fof_x190 + _fof_x192))) | ((_fof_x189 <= _fof_x190) & ((_fof_x189 + _fof_x191) > (_fof_x190 + _fof_x192)))));
    } else {
        return (((_fof_x189 <= _fof_x190) & ((_fof_x189 + _fof_x191) >= (_fof_x190 + _fof_x192))));
    }
}
 
bool is_copy(struct  capability* left,struct  capability* right) {
    int8_t _fof_x181;
    struct  capability* left__175;
    struct  capability left__175__176;
    enum objtype left__175__176__179;
    struct  capability* right__177;
    struct  capability right__177__178;
    enum objtype right__177__178__180;
 
    left__175 = left;
    left__175__176 = *left__175;
    right__177 = right;
    right__177__178 = *right__177;
    left__175__176__179 = left__175__176.type;
    right__177__178__180 = right__177__178.type;
    if ((left__175__176__179 != right__177__178__180)){
        return (0);
    } else {
    }
    switch (left__175__176__179) {
        case ObjType_IPI: {
            return (1);
            break;
        }
        case ObjType_PerfMon: {
            return (1);
            break;
        }
        case ObjType_IRQTable: {
            return (1);
            break;
        }
        case ObjType_Kernel: {
            return (1);
            break;
        }
        case ObjType_Null: {
            return (0);
            break;
        }
        default: {
        }
    }
    _fof_x181 = compare_caps(left,right,0);
    return ((_fof_x181 == 0));
}
 
bool is_equal_type(enum objtype left_type,enum objtype right_type) {
 
    return ((left_type == right_type));
}
 
bool is_well_founded(enum objtype src_type,enum objtype dest_type) {
 
    switch (dest_type) {
        case ObjType_KernelControlBlock: {
            return (((src_type == ObjType_RAM) | 0));
            break;
        }
        case ObjType_VNode_ARM_l2: {
            return (((src_type == ObjType_RAM) | 0));
            break;
        }
        case ObjType_VNode_ARM_l1: {
            return (((src_type == ObjType_RAM) | 0));
            break;
        }
        case ObjType_VNode_x86_32_ptable: {
            return (((src_type == ObjType_RAM) | 0));
            break;
        }
        case ObjType_VNode_x86_32_pdir: {
            return (((src_type == ObjType_RAM) | 0));
            break;
        }
        case ObjType_VNode_x86_32_pdpt: {
            return (((src_type == ObjType_RAM) | 0));
            break;
        }
        case ObjType_VNode_x86_64_ptable: {
            return (((src_type == ObjType_RAM) | 0));
            break;
        }
        case ObjType_VNode_x86_64_pdir: {
            return (((src_type == ObjType_RAM) | 0));
            break;
        }
        case ObjType_VNode_x86_64_pdpt: {
            return (((src_type == ObjType_RAM) | 0));
            break;
        }
        case ObjType_VNode_x86_64_pml4: {
            return (((src_type == ObjType_RAM) | 0));
            break;
        }
        case ObjType_DevFrame: {
            return (((src_type == ObjType_PhysAddr) | (src_type == ObjType_DevFrame)));
            break;
        }
        case ObjType_Frame: {
            return (((src_type == ObjType_RAM) | (src_type == ObjType_Frame)));
            break;
        }
        case ObjType_EndPoint: {
            return (((src_type == ObjType_Dispatcher) | 0));
            break;
        }
        case ObjType_Dispatcher: {
            return (((src_type == ObjType_RAM) | 0));
            break;
        }
        case ObjType_CNode: {
            return (((src_type == ObjType_RAM) | 0));
            break;
        }
        case ObjType_RAM: {
            return (((src_type == ObjType_PhysAddr) | (src_type == ObjType_RAM)));
            break;
        }
        case ObjType_PhysAddr: {
            return ((0 | (src_type == ObjType_PhysAddr)));
            break;
        }
        default: {
            return (0);
        }
    }
}
 
 
 
