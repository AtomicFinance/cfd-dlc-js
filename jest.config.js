module.exports = {
  transform: {
    "^.+\\.ts?$": "ts-jest",
  },
  preset: "ts-jest",
  testEnvironment: "node",
  globals: {
    "ts-jest": {
      tsconfig: "tsconfig.json",
    },
  },
  testMatch: ["<rootDir>/wrap_js/__test__/*.spec.ts"],
  modulePathIgnorePatterns: [
    "<rootDir>/external/libwally-core/src/wrap_js/",
    "<rootDir>/external/libwally-core/package.json",
  ],
  watchPathIgnorePatterns: [
    "<rootDir>/external/libwally-core/",
  ],
};
