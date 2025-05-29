module.exports = {
  preset: 'ts-jest',
  testEnvironment: 'node',
  transform: {
    "^.+\\.ts?$": ["ts-jest", {
      tsconfig: "tsconfig.json",
    }],
  },
  testMatch: ["**/integration_tests/__tests__/*.spec.ts"],
  moduleFileExtensions: ['ts', 'js', 'json'],
};
