#pragma once

namespace npp {
  class Screen {
    public:
      Screen(unsigned int flags);
      ~Screen();
      void refresh(void) const;
  };
}
