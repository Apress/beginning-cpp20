export module truckload:shared_box;

import <memory>;
import box;

export using SharedBox = std::shared_ptr<Box>;
