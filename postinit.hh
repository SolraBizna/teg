#ifndef POSTINITHH
#define POSTINITHH

#ifndef TEG_NO_POSTINIT
#include "teg.hh"
#include <functional>

namespace TEG {
  /* Usage: (in global scope ONLY)
     static TEG::PostInitHandler whatever(priority, []() {
       // code goes here
     });
     where priority determines the order of execution. (If not specified, the
     priority is 0.)
     Handlers are executed after all C++ static initialization is completed,
     and after TEG has done all TEG-specific initialization (e.g. command line
     handling), but before teg_main is called.
     Execution order: 0, 1, ..., max(priority), min(priority), ..., -2, -1
     Don't provide absurdly large or small priorities; they're handled with
     arrays! Only use non-zero priorities to ensure that your InitHandler runs
     before/after a specific other InitHandler (or InitHandlers) that it
     depends on (or is depended on by) */
  struct PostInitHandler {
    PostInitHandler(int priority, std::function<void()> handler);
    PostInitHandler(std::function<void()> handler)
      : PostInitHandler(0, handler) {}
    /* We do not provide a destructor. We assume we will be used correctly. */
  };
#if WE_ARE_IN_CHARGE_OF_POSTINIT_HANDLING || WE_ARE_POSTINIT_CC
  void DoPostInit();
#endif
}
#endif

#endif
