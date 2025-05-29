module.exports = {
  parser: '@typescript-eslint/parser',
  parserOptions: {
    ecmaVersion: 2020,
    sourceType: 'module',
  },
  plugins: ['@typescript-eslint'],
  extends: [
    'eslint:recommended',
    'plugin:@typescript-eslint/recommended',
  ],
  rules: {
    // Disable strict rules that would require major code changes
    'new-cap': 'off',
    'max-len': 'off',
    'no-console': 'off',
    'require-jsdoc': 'off',
    'valid-jsdoc': 'off',
    
    // Keep important TypeScript rules but make them warnings
    '@typescript-eslint/no-unused-vars': ['warn', { argsIgnorePattern: '^_' }],
    '@typescript-eslint/explicit-function-return-type': 'off',
    '@typescript-eslint/explicit-module-boundary-types': 'off',
    '@typescript-eslint/no-explicit-any': 'warn',
    
    // Basic formatting
    'semi': ['error', 'always'],
    'quotes': ['error', 'single', { allowTemplateLiterals: true }],
  },
  env: {
    node: true,
    jest: true,
    es6: true,
  },
  ignorePatterns: [
    'node_modules/',
    'build/',
    'wrap_js/build/',
    '*.js',
    '*.d.ts',
  ],
}; 