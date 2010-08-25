<?php


function taxonomy_page_title_alter(&$title) {
  // If we're looking at a taxonomy term page, get the term title
  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
    $term = taxonomy_get_term(arg(2));
    if (variable_get('page_title_vocab_'. $term->vid .'_showfield', 0) && ($term_title = page_title_load_title($term->tid, 'term'))) {
      $title = $term_title;
    }
  }
}



function taxonomy_page_title_pattern_alter(&$pattern, &$types) {
  // Taxonomy Term Page
  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2)) && module_exists('taxonomy')) {
    $types['taxonomy'] = taxonomy_get_term(arg(2));
    $pattern = variable_get('page_title_vocab_'. $types['taxonomy']->vid, '');
  }
}
