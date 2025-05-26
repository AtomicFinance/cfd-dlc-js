#!/bin/bash

prebuild \
  --backend cmake-js \
  -t 20.18.0 \
  -t 18.18.2 \
  -t 16.20.2 \
  -t 15.1.0 \
  -t 14.18.1 \
  -t 12.18.1 \
  -r node \
  --verbose \
  --include-regex ".*(node|a|so|dll|dylib)$" \
  -- \
  -O build \
  --CDENABLE_SHARED=off \
  --CDENABLE_CAPI=off \
  --CDENABLE_TESTS=off \
  --CDENABLE_JSONAPI=off \
  --CDENABLE_JS_WRAPPER=off \
  --CDTARGET_RPATH="@executable_path;/usr/local/lib;/usr/local/lib64;./node_modules/cfd-dlc-js/wrap_js/build/Release;../node_modules/cfd-dlc-js/wrap_js/build/Release;../../node_modules/cfd-dlc-js/wrap_js/build/Release;../../../node_modules/cfd-dlc-js/wrap_js/build/Release;../../../../node_modules/cfd-dlc-js/wrap_js/build/Release;../../../../../node_modules/cfd-dlc-js/wrap_js/build/Release;../../../../../../node_modules/cfd-dlc-js/wrap_js/build/Release;./build/Release;./wrap_js/build/Release;./wrap_js/dl_lib/lib" \
  -C \
  --CDnapi_build_version=3 \
  --CDCMAKE_POLICY_VERSION_MINIMUM=3.5