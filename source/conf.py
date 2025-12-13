# Configuration file for the Sphinx documentation builder.

# -- Project information

project = '<RISC-V Docs Template>'
copyright = '2024, RISC-V International'
author = 'RISC-V International'
release = '0.1'
version = '0.1.0'

# -- General configuration
extensions = [
    'sphinx.ext.duration',
    'sphinx.ext.doctest',
    'sphinx.ext.autodoc',
    'sphinx.ext.autosummary',
    'sphinx.ext.intersphinx',
    'myst_parser'
]

source_suffix = {
    '.rst': 'restructuredtext',
    '.md': 'markdown',
}

master_doc = 'index'

intersphinx_mapping = {
    'python': ('https://docs.python.org/3/', None),
    'sphinx': ('https://www.sphinx-doc.org/en/master/', None),
}
intersphinx_disabled_domains = ['std']

templates_path = ['_templates']

# -- Options for HTML output
github_url = 'https://github.com/riscv-admin/template-docs-rtd'
html_sho_sourcelink = True

html_theme = 'sphinx_rtd_theme'

html_static_path = ['_static']
html_css_files = ['css/risc-v.css']
html_style = 'css/risc-v.css'

html_logo = 'RISC-V-Logo.svg'

html_theme_options = {
#   'analytics_id': 'G-XXXXXXXXXX',  #  Provided by Google in your dashboard
#   'analytics_anonymize_ip': False,
    'logo_only': False,
    'display_version': True,
    'prev_next_buttons_location': 'bottom',
    'style_external_links': False,
    'vcs_pageview_mode': '',
    'style_nav_header_background': 'white',
    # Toc options
    'collapse_navigation': True,
    'sticky_navigation': True,
    'navigation_depth': 4,
    'includehidden': False,
    'titles_only': False
}

html_show_license = True

html_favicon = '_static/riscv-favicon-32x32.png'

# -- Options for EPUB output
epub_show_urls = 'footnote'
