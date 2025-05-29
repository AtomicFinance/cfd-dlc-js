module.exports = {
  preset: 'ts-jest',
  testEnvironment: 'node',
  transform: {
    "^.+\\.ts?$": ["ts-jest", {
      tsconfig: "tsconfig.json",
    }],
  },
  testMatch: ["<rootDir>/wrap_js/__test__/*.spec.ts"],
  moduleFileExtensions: ['ts', 'js', 'json', 'node'],
  collectCoverageFrom: [
    'wrap_js/**/*.ts',
    '!wrap_js/**/*.d.ts',
  ],
  // Handle native modules
  moduleNameMapper: {
    '\\.node$': '<rootDir>/__mocks__/nodeMock.js'
  },
  setupFilesAfterEnv: ['<rootDir>/jest.setup.js'],
};
