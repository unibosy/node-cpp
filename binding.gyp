{
  'targets': [
    {
      'target_name': 'agorasdk',
      'include_dirs': [
      '../agorasdk',
      './sdk/include',
      './sdk/include/base'
      ],
      'sources': [
      './agora_node_ext/agora_node_recording.h',
      './agora_node_ext/agora_node_recording.cpp',
      './agora_node_ext/node_log.h',
      './agora_node_ext/node_log.cpp',
      './agora_node_ext/node_napi_api.cpp',
      './agora_node_ext/node_napi_api.h',
      './agora_node_ext/node_uid.cpp',
      './agora_node_ext/node_uid.h',
      './agora_node_ext/agora_node_ext.h',
      './agora_node_ext/agora_node_ext.cpp',
      ],
      'conditions': [
        [
        'OS=="linux"',
        {
            'library_dirs': [
            './sdk/lib/'
            ],
            "link_settings": {
            "libraries": [
            ]
            },
            'sources': [],
            'defines!': [
            ],
        }
        ]
      ]
    }
  ]
}