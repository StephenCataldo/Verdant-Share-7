<?php
function verdant_share_flag_default_flags() {


	$flags = array();
	// Exported flag: "Remove from your match list".
	$flags['share_remove'] = array (
		'content_type' => 'node',
		'title' => 'Remove from your match list',
		'global' => '0',
		'types' => 
		array (
			0 => 'share_flight',
			1 => 'share_ride',
			2 => 'share_room',
		),
		'flag_short' => 'Bottom of list?',
		'flag_long' => 'Click to move this possible match to the bottom of your list (when you reload your browser).',
		'flag_message' => '',
		'unflag_short' => 'Restore to list.',
		'unflag_long' => 'Click to indicate that you are again considering this match (when you reload your browser).',
		'unflag_message' => '',
		'unflag_denied_text' => '',
		'link_type' => 'toggle',
		'roles' => 
		array (
			'flag' => 
			array (
				0 => 2,
			),
			'unflag' => 
			array (
				0 => 2,
			),
		),
		'show_on_page' => 1,
		'show_on_teaser' => 1,
		'show_on_form' => 0,
		'access_author' => '',
		'i18n' => 0,
		'api_version' => 2,
	);
	// Exported flag: "Prefer this share".
	$flags['share_prefer'] = array (
		'content_type' => 'node',
		'title' => 'Prefer this share',
		'global' => '0',
		'types' => 
		array (
			0 => 'share_flight',
			1 => 'share_ride',
			2 => 'share_room',
		),
		'flag_short' => 'Favorite?',
		'flag_long' => 'Click to move this possible match to the top of your list.',
		'flag_message' => '',
		'unflag_short' => 'Favorite (undo)',
		'unflag_long' => 'Click to remove this match from the favorites at the top of your list.',
		'unflag_message' => '',
		'unflag_denied_text' => '',
		'link_type' => 'toggle',
		'roles' => 
		array (
			'flag' => 
			array (
				0 => 2,
			),
			'unflag' => 
			array (
				0 => 2,
			),
		),
		'show_on_page' => 1,
		'show_on_teaser' => 1,
		'show_on_form' => 0,
		'access_author' => '',
		'i18n' => 0,
		'api_version' => 2,
	);
	return $flags;


}
?>
