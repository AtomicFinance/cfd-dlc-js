#!/bin/bash

prebuild \
  --backend cmake-js \
  -t 7.0.0 \
  -t 7.3.0 \
  -t 8.0.0 \
  -t 9.0.0 \
  -r electron \
  --verbose \
  --include-regex ".*(node|a|so|dll|dylib)$" \
  -- \
  -O build \
  --CDENABLE_SHARED=off \
  --CDENABLE_CAPI=off \
  --CDENABLE_TESTS=off \
  --CDENABLE_JSONAPI=off \
  --CDENABLE_JS_WRAPPER=off \
  --CDTARGET_RPATH="@executable_path;/usr/local/lib;/usr/local/lib64;\$\$ORIGIN/node_modules/cfd-dlc-js/wrap_js/build/Release;\$ORIGIN/node_modules/cfd-dlc-js/wrap_js/build/Release;\$ORIGIN/../node_modules/cfd-dlc-js/wrap_js/build/Release;\$ORIGIN/../../node_modules/cfd-dlc-js/wrap_js/build/Release;\$ORIGIN/../../../node_modules/cfd-dlc-js/wrap_js/build/Release;\$ORIGIN/../../../../node_modules/cfd-dlc-js/wrap_js/build/Release;\$ORIGIN/../../../../../node_modules/cfd-dlc-js/wrap_js/build/Release;\$ORIGIN/../../../../../../node_modules/cfd-dlc-js/wrap_js/build/Release;\$ORIGIN/build/Release;\$ORIGIN/wrap_js/build/Release;\$ORIGIN/wrap_js/dl_lib/lib" \
  -C \
  --CDnapi_build_version=3 \
  --CDCMAKE_POLICY_VERSION_MINIMUM=3.5