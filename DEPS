# This file contains dependencies for WebRTC.

vars = {
  'chromium_git': 'https://chromium.googlesource.com',
  'chromium_revision': 'cf58257d56a079b191b9d476fb12f2e58aaf4bda',
  'boringssl_git': 'https://boringssl.googlesource.com',
  'boringssl_revision': '3120950b1e27635ee9b9d167052ce11ce9c96fd4',
}
deps = {
  # TODO(kjellander): Move this to be Android-only once the libevent dependency
  # in base/third_party/libevent is solved.
  'src/base':
    Var('chromium_git') + '/chromium/src/base' + '@' + '9d97c4401546953493165316699d12c7561e3247',
  'src/build':
    Var('chromium_git') + '/chromium/src/build' + '@' + 'e9a431763efcffd2b1c211badf304e2603c1d980',
  'src/buildtools':
    Var('chromium_git') + '/chromium/buildtools.git' + '@' + '1dcd1bdbe93467531a50b60dbd18860803ca7be1',
  'src/testing':
    Var('chromium_git') + '/chromium/src/testing' + '@' + '86da9bf8b52f486ab4bcb62cdb9de906c7a846a7',
  'src/third_party':
    Var('chromium_git') + '/chromium/src/third_party' + '@' + 'f72956cf4fd72ffe061cca382808d20864b47718',
  'src/third_party/boringssl/src':
   Var('boringssl_git') + '/boringssl.git' + '@' +  Var('boringssl_revision'),
}
deps_os = {
}
pre_deps_hooks = [
]
hooks = [
]
recursedeps = [
]