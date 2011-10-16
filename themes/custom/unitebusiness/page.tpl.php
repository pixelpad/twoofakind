  <?php print render($page['header']); ?>

<!-- Top reveal (slides open, add class "topReveal" to links for open/close toggle ) -->
<?php if (!($user->uid > 0)) { ?> 
<div id="ContentPanel">

	<!-- close button -->
	<a href="#" class="topReveal closeBtn"><?php print t("Close") ?></a>
	
	<div class="contentArea">

		<!-- New member registration -->
		<div class="right m7">
			<h4><?php print t("Not a member yet?") ?><span><?php print t("Register now and get started.") ?></span></h4>
			<button type="button" onclick="parent.location='<?php print url("user/register") ?>'"><?php print t("Register for an account") ?></button>
		</div>
		
		<!-- Alternate Login -->				
		<div>
			<form class="loginForm" method="post" action="<?php print url("user") ?>" style="height:auto;">
				<div id="loginBg"><img src="<?php print base_path().drupal_get_path('theme', 'unitebusiness'); ?>/images/icons/lock-and-key-110.png" width="110" height="110" alt="lock and key" /></div>
				<h2 style="margin-top: 20px;"><?php print t("Sign in to your account.") ?></h2>
				<fieldset>
					<legend><?php print t("Account Login") ?></legend>
					<div class="left m1"">
						<label for="RevealUsername" class="overlabel"><?php print t("Username") ?></label>
						<input id="RevealUsername" name="name" type="text" class="loginInput textInput rounded" />
					</div>
					<div class="left m2">
						<label for="RevealPassword" class="overlabel"><?php print t("Password") ?></label>
						<input id="RevealPassword" name="pass" type="password" class="loginInput textInput rounded" />
					</div>
					<div class="left m3">
						<input type="submit" name="op" id="edit-submit1" value="<?php print t("Log in") ?>"  class="form-submit" />
					</div>
				</fieldset>
				<div class="left noMargin">
					<a href="<?php print url("user/password") ?>"><?php print t("Forgot your password?") ?></a>
				</div>
				<input type="hidden" name="form_id" id="edit-user-login" value="user_login"  />
			</form>		
		</div>
		
		<!-- End of Content -->
		<div class="clear"></div>
	
	</div>
</div>
<?php } ?>
<!-- Site Container -->
<div id="Wrapper">
	<div id="PageWrapper">
		<div class="pageTop"></div>
		<div id="Header">
		
			<!-- Main Menu -->
			<div id="MenuWrapper">
				<div id="MainMenu">
					<div id="MmLeft"></div>
					<div id="MmBody">
						
						<!-- Main Menu Links -->
						<?php print str_replace(array('class="menu"'), array('class="sf-menu"'), drupal_render(menu_tree('main-menu'))) ?>
						
						<div class="mmDivider"></div>				
						
						<!-- Extra Menu Links -->
						<ul id="MmOtherLinks" class="sf-menu">
							<li><a href="/rss.xml"><span class="mmFeeds"><?php print t("Feeds") ?></span></a></li>
							<?php if ($user->uid > 0) { ?> 
							<li><a href="<?php print url('user/logout') ?>"><span class="mmLogin"><?php print t("LogOut") ?></span></a></li>
							<?php } else { ?>
							<li><a href="#ContentPanel" class="topReveal"><span class="mmLogin"><?php print t("Login") ?></span></a></li>
							<?php } ?>
						</ul>
						
					</div>
					<div id="MmRight"></div>
				</div>
			</div>
			
			<!-- Search -->
			<div id="Search">
				<form action="<?php print url("search/node") ?>" id="SearchForm" method="post">
					<div class="m4"><input type="text" name="keys" id="SearchInput" value="" /></div>
					<div class="m4"><input type="submit" name="op" id="SearchSubmit" class="noStyle" value="<?php print t("Search") ?>" /></div>
					<input type="hidden" name="form_token" id="edit-search-block-form-form-token" value="<?php print drupal_get_token("search_form") ?>"  />
					<input type="hidden" name="form_id" id="edit-search-block-form" value="search_form"  />
				</form>
			</div>
			
			<!-- Logo -->
			<div id="Logo">
				<a href="/"></a>
			</div>
			
			<!-- End of Content -->
			<div class="clear"></div>
		
		</div>

		

		<?php if (arg(0) == 'portfolio') { ?>
		<div class="pageMain"><div class="full-page">
			<h1 class="headline"><strong><?php print $title ?></strong></h1>
			<div class="hr"></div>
			<div class="breadcrumbs"><?php print $breadcrumb; ?></div>
			<?php if (!empty($messages)): print $messages; endif; ?>
			<?php if ($tabs): print ''. render($tabs) .''; endif; ?>
			<?php //if ($tabs2): print ''. $tabs2 .''; endif; ?>
			<?php if (!empty($help)): print $help; endif; ?>
			<?php if ($page['portfolio_top_img']): ?><br /><?php print render($page['portfolio_top_img']); ?><br /><?php endif;?>
			<div class="clear"></div><br />
		</div></div>
		
		<?php if ($page['portfolio_top_txt']): ?>
		<div class="pageBottom"></div>
		<div class="pageTop"></div>
		<div class="pageMain">
			<div class="contentArea">
				<div class="full-page">
					<?php print render($page['portfolio_top_txt']); ?>
				</div>
					<!-- End of Content -->
				<div class="clear"></div>
			</div>
		</div>
		<?php endif;?>
		<div class="pageBottom"></div>
		<div class="pageTop"></div>

		<?php } ?>

		<div class="pageMain">

		<?php if ($is_front): ?>
		<?php if ($page['slide_shows']): ?><?php print render($page['slide_shows']); ?><?php endif;?>
		<div id="Showcase">
			<div class="two-thirds">
				<?php print render($page['home_banner_1']); ?>
			</div>
			<div class="one-third">
				<?php print render($page['home_banner_2']); ?>
			</div>
			<div class="hr"></div>
		</div>
		<?php endif;?>

			<!-- Page Content -->
			<div class="contentArea">
			<?php if (arg(0) == 'portfolio') { ?>
				<div class="full-page">

					<div class="portfolio">
					<?php print render($page['content']); ?>
					</div>
					<div class="clear"></div>
				</div>
				<div class="clear"></div>
			<?php } else {?>
				<div class="two-thirds">
					<?php if ($is_front): ?>
					<?php if ($page['home_banner_3']): ?><?php print render($page['home_banner_3']); ?><?php endif;?>
					<?php if ($page['featured_content']): ?><?php print render($page['featured_content']); ?><?php endif;?>
					<br />
					<?php endif;?>
					<?php if ($title): ?>
					<h1 class="headline"><strong><?php echo $title ?></strong></h1>
					<div class="hr"></div>
					<?php endif;?>
					<!-- Breadcrumbs -->
					<div class="breadcrumbs"><?php print $breadcrumb; ?></div>
					<?php if (!empty($messages)): print $messages; endif; ?>
					<?php if ($tabs): print ''. render($tabs) .''; endif; ?>
					<?php //if ($tabs2): print ''. render($tabs2) .''; endif; ?>
					<?php if (!empty($help)): print $help; endif; ?>
					<?php print render($page['content']); ?>
					<!-- End of Content -->
					<div class="clear"></div>
										
				</div>
				
				<div class="one-third">
				<?php if ($page['sidebar_right']): ?><?php print render($page['sidebar_right']); ?><?php endif;?>
					
				</div>
				
				<!-- End of Content -->
				<div class="clear"></div>
			<?php } ?>
			</div>

		</div>
		
		<!-- Footer -->
		<div id="Footer">
			<div id="FooterTop"></div>
			<div id="FooterContent">
			
				<div class="contentArea">
				
					<!-- Column 1 -->
					<div class="one-third">
						<?php if ($page['footer_1']): ?><?php print render($page['footer_1']); ?><?php endif;?>
					</div>

					<!-- Column 2 -->
					<div class="one-third">
						<?php if ($page['footer_2']): ?><?php print render($page['footer_2']); ?><?php endif;?>
					</div>

					<!-- Column 3 -->
					<div class="one-third last">
						<?php if ($page['footer_3']): ?><?php print render($page['footer_3']); ?><?php endif;?>
					</div>
					
					<!-- End of Content -->
					<div class="clear"></div>
	
				</div>
					
			</div>
			<div id="FooterBottom"></div>
			
		</div>
		
		<!-- Copyright/legal text -->
		<div id="Copyright">
			<p><?php print render($page['footer']); ?></p>
		</div>		
	</div>
</div>
<?php //print $closure; ?>
<!-- Activate Font Replacement (cufon) -->
<script type="text/javascript"> Cufon.now(); </script>