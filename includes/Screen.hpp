#pragma once

namespace npp {
  class Screen {
    public:
      explicit Screen(unsigned int flags);
      ~Screen();

    public:
      void refresh(void) const;
  };
}
