static NORETURN void die_want_option(const char *option_name)
{
	die(_("option '%s' requires a value"), option_name);
}
	if (!strcasecmp(var, "context") || !strcasecmp(var, "plain"))
	if (!strcasecmp(var, "meta"))
		return DIFF_METAINFO;
	if (!strcasecmp(var, "frag"))
		return DIFF_FRAGINFO;
	if (!strcasecmp(var, "old"))
		return DIFF_FILE_OLD;
	if (!strcasecmp(var, "new"))
		return DIFF_FILE_NEW;
	if (!strcasecmp(var, "commit"))
		return DIFF_COMMIT;
	if (!strcasecmp(var, "whitespace"))
		return DIFF_WHITESPACE;
	if (!strcasecmp(var, "func"))
		return DIFF_FUNCINFO;
	if (!strcasecmp(var, "oldmoved"))
		return DIFF_FILE_OLD_MOVED;
	if (!strcasecmp(var, "oldmovedalternative"))
		return DIFF_FILE_OLD_MOVED_ALT;
	if (!strcasecmp(var, "oldmoveddimmed"))
		return DIFF_FILE_OLD_MOVED_DIM;
	if (!strcasecmp(var, "oldmovedalternativedimmed"))
		return DIFF_FILE_OLD_MOVED_ALT_DIM;
	if (!strcasecmp(var, "newmoved"))
		return DIFF_FILE_NEW_MOVED;
	if (!strcasecmp(var, "newmovedalternative"))
		return DIFF_FILE_NEW_MOVED_ALT;
	if (!strcasecmp(var, "newmoveddimmed"))
		return DIFF_FILE_NEW_MOVED_DIM;
	if (!strcasecmp(var, "newmovedalternativedimmed"))
		return DIFF_FILE_NEW_MOVED_ALT_DIM;
	return -1;
static int git_config_rename(const char *var, const char *value)
		return error(_("color moved setting must be one of 'no', 'default', 'zebra', 'dimmed_zebra', 'plain'"));
	external_diff_cmd = getenv("GIT_EXTERNAL_DIFF");
static int fill_mmfile(mmfile_t *mf, struct diff_filespec *one)
	else if (diff_populate_filespec(one, 0))
static unsigned long diff_filespec_size(struct diff_filespec *one)
	diff_populate_filespec(one, CHECK_SIZE_ONLY);
static void emit_line_0(struct diff_options *o, const char *set, const char *reset,
	int nofirst;
	if (len == 0) {
		has_trailing_newline = (first == '\n');
		has_trailing_carriage_return = (!has_trailing_newline &&
						(first == '\r'));
		nofirst = has_trailing_newline || has_trailing_carriage_return;
	} else {
		has_trailing_newline = (len > 0 && line[len-1] == '\n');
		if (has_trailing_newline)
			len--;
		has_trailing_carriage_return = (len > 0 && line[len-1] == '\r');
		if (has_trailing_carriage_return)
			len--;
		nofirst = 0;
	if (len || !nofirst) {
		if (!nofirst)
			fputc(first, file);
		fwrite(line, len, 1, file);
	}
	emit_line_0(o, set, reset, line[0], line+1, len-1);
static int moved_entry_cmp(const struct diff_options *diffopt,
			   const struct moved_entry *a,
			   const struct moved_entry *b,
				    diffopt->xdl_opts);
	ret->ent.hash = xdiff_hash_string(l->line, l->len, o->xdl_opts);
		hashmap_add(hm, key);
static int shrink_potential_moved_blocks(struct moved_entry **pmb,
		while (lp < pmb_nr && pmb[lp])
		while (rp > -1 && !pmb[rp])
			pmb[rp] = NULL;
static void adjust_last_block(struct diff_options *o, int n, int block_length)
		return;
				return;
	struct moved_entry **pmb = NULL; /* potentially moved blocks */
	int n, flipped_block = 1, block_length = 0;
		int i;
			match = hashmap_get(hm, key, o);
			match = hashmap_get(hm, key, o);
			flipped_block = 1;
		l->flags |= DIFF_SYMBOL_MOVED_LINE;

		if (o->color_moved == COLOR_MOVED_PLAIN)
		/* Check any potential block runs, advance each or nullify */
		for (i = 0; i < pmb_nr; i++) {
			struct moved_entry *p = pmb[i];
			struct moved_entry *pnext = (p && p->next_line) ?
					p->next_line : NULL;
			if (pnext && !hm->cmpfn(o, pnext, match, NULL)) {
				pmb[i] = p->next_line;
			} else {
				pmb[i] = NULL;
			}
		}
			for (; match; match = hashmap_get_next(hm, match)) {
				pmb[pmb_nr++] = match;
			flipped_block = (flipped_block + 1) % 2;
			adjust_last_block(o, n, block_length);
		block_length++;

		if (flipped_block)
			l->flags |= DIFF_SYMBOL_MOVED_LINE_ALT;
				const char *set, const char *reset,
				const char *line, int len, char sign,
	if (!ws)
		emit_line_0(o, set, reset, sign, line, len);
	else if (blank_at_eof)
		emit_line_0(o, ws, reset, sign, line, len);
		emit_line_0(o, set, reset, sign, "", 0);
	const char *context, *reset, *set, *meta, *fraginfo;
		emit_line_0(o, context, reset, '\\',
		emit_line_ws_markup(o, set, reset, line, len, ' ',
		emit_line_ws_markup(o, set, reset, line, len, '+',
		emit_line_ws_markup(o, set, reset, line, len, '-',
		die("BUG: unknown diff symbol");
	struct emitted_diff_symbol e = {line, len, flags, s};
static void emit_add_line(const char *reset,
			  struct emit_callback *ecbdata,
static void emit_del_line(const char *reset,
			  struct emit_callback *ecbdata,
static void emit_context_line(const char *reset,
			      struct emit_callback *ecbdata,
	strbuf_add(&msgbuf, line, ep - line);
static struct diff_tempfile *claim_diff_tempfile(void) {
	die("BUG: diff is failing to clean up its tempfiles");
	const char *reset = diff_get_color(ecb->color_diff, DIFF_RESET);
			emit_del_line(reset, ecb, data, len);
			emit_add_line(reset, ecb, data, len);
	size_one = fill_textconv(textconv_one, one, &data_one);
	size_two = fill_textconv(textconv_two, two, &data_two);
	ecbdata.ws_rule = whitespace_rule(name_b);
static void fn_out_diff_words_aux(void *priv, char *line, unsigned long len)
	int minus_first, minus_len, plus_first, plus_len;
	if (line[0] != '@' || parse_hunk_header(line, len,
			&minus_first, &minus_len, &plus_first, &plus_len))
		return;

	if (xdi_diff_outf(&minus, &plus, fn_out_diff_words_aux, diff_words,
			  &xpp, &xecfg))
static void diff_filespec_load_driver(struct diff_filespec *one)
		one->driver = userdiff_find_by_path(one->path);
static const char *userdiff_word_regex(struct diff_filespec *one)
	diff_filespec_load_driver(one);
		o->word_regex = userdiff_word_regex(one);
		o->word_regex = userdiff_word_regex(two);
			die ("Invalid regular expression: %s",
			     o->word_regex);
static unsigned long sane_truncate_line(struct emit_callback *ecb, char *line, unsigned long len)
	const char *reset = diff_get_color(ecbdata->color_diff, DIFF_RESET);
		len = sane_truncate_line(ecbdata, line, len);
		emit_add_line(reset, ecbdata, line + 1, len - 1);
		emit_del_line(reset, ecbdata, line + 1, len - 1);
		emit_context_line(reset, ecbdata, line + 1, len - 1);
struct diffstat_t {
	int nr;
	int alloc;
	struct diffstat_file {
		char *from_name;
		char *name;
		char *print_name;
		const char *comments;
		unsigned is_unmerged:1;
		unsigned is_binary:1;
		unsigned is_renamed:1;
		unsigned is_interesting:1;
		uintmax_t added, deleted;
	} **files;
};

	 * scale linearly as if the alloted width is one column shorter
		int content_changed;
		if (p->one->oid_valid && p->two->oid_valid)
			content_changed = oidcmp(&p->one->oid, &p->two->oid);
		else
			content_changed = 1;

		if (!content_changed) {
			diff_populate_filespec(p->one, 0);
			diff_populate_filespec(p->two, 0);
			diffcore_count_changes(p->one, p->two, NULL, NULL,
			diff_populate_filespec(p->one, CHECK_SIZE_ONLY);
			diff_populate_filespec(p->two, CHECK_SIZE_ONLY);
		 * be identical, but since content_changed is true, we
static void free_diffstat_info(struct diffstat_t *diffstat)
	/* line[1] thru line[marker_size-1] are same as firstchar */
	} else if (line[0] == '@') {
		char *plus = strchr(line, '+');
		if (plus)
			data->lineno = strtol(plus, NULL, 10) - 1;
		else
			die("invalid diff");
		char *s = xstrfmt("%lu", orig_size);
int diff_filespec_is_binary(struct diff_filespec *one)
		diff_filespec_load_driver(one);
				diff_populate_filespec(one, CHECK_BINARY);
static const struct userdiff_funcname *diff_funcname_pattern(struct diff_filespec *one)
	diff_filespec_load_driver(one);
struct userdiff_driver *get_textconv(struct diff_filespec *one)
	diff_filespec_load_driver(one);
	return userdiff_get_textconv(one->driver);
		textconv_one = get_textconv(one);
		textconv_two = get_textconv(two);
		    (textconv_one || !diff_filespec_is_binary(one)) &&
		    (textconv_two || !diff_filespec_is_binary(two))) {
						textconv_one, textconv_two, o);
	    ( (!textconv_one && diff_filespec_is_binary(one)) ||
	      (!textconv_two && diff_filespec_is_binary(two)) )) {
			if (!oidcmp(&one->oid, &two->oid)) {
		if (fill_mmfile(&mf1, one) < 0 || fill_mmfile(&mf2, two) < 0)
		const char *diffopts = getenv("GIT_DIFF_OPTS");
		mf1.size = fill_textconv(textconv_one, one, &mf1.ptr);
		mf2.size = fill_textconv(textconv_two, two, &mf2.ptr);
		pe = diff_funcname_pattern(one);
			pe = diff_funcname_pattern(two);
		ecbdata.ws_rule = whitespace_rule(name_b);
		ecbdata.header = header.len ? &header : NULL;
		if (xdi_diff_outf(&mf1, &mf2, fn_out_consume, &ecbdata,
				  &xpp, &xecfg))
	same_contents = !oidcmp(&one->oid, &two->oid);
	if (diff_filespec_is_binary(one) || diff_filespec_is_binary(two)) {
			data->added = diff_filespec_size(two);
			data->deleted = diff_filespec_size(one);
		diff_populate_filespec(one, 0);
		diff_populate_filespec(two, 0);
		if (fill_mmfile(&mf1, one) < 0 || fill_mmfile(&mf2, two) < 0)
		if (xdi_diff_outf(&mf1, &mf2, diffstat_consume, diffstat,
				  &xpp, &xecfg))
	data.ws_rule = whitespace_rule(attr_path);
	data.conflict_marker_size = ll_merge_marker_size(attr_path);
	if (fill_mmfile(&mf1, one) < 0 || fill_mmfile(&mf2, two) < 0)
	if (diff_filespec_is_binary(two))
		if (xdi_diff_outf(&mf1, &mf2, checkdiff_consume, &data,
static int reuse_worktree_file(const char *name, const struct object_id *oid, int want_file)
	if (!active_cache)
	if (!FAST_WORKING_DIRECTORY && !want_file && has_sha1_pack(oid->hash))
	if (!want_file && would_convert_to_git(&the_index, name))
	pos = cache_name_pos(name, len);
	ce = active_cache[pos];
	if (oidcmp(oid, &ce->oid) || !S_ISREG(ce->ce_mode))
	    (!lstat(name, &st) && !ce_match_stat(ce, &st, 0)))
int diff_populate_filespec(struct diff_filespec *s, unsigned int flags)
	    reuse_worktree_file(s->path, &s->oid, 0)) {
		if (size_only && !would_convert_to_git(&the_index, s->path))
		if (convert_to_git(&the_index, s->path, s->data, s->size, &buf, conv_flags)) {
			type = sha1_object_info(s->oid.hash, &s->size);
		s->data = read_sha1_file(s->oid.hash, &type, &s->size);
static void prep_temp_blob(const char *path, struct diff_tempfile *temp,
	if (convert_to_working_tree(path,
static struct diff_tempfile *prepare_temp_file(const char *name,
		struct diff_filespec *one)
	     reuse_worktree_file(name, &one->oid, 1))) {
			prep_temp_blob(name, temp, sb.buf, sb.len,
		if (diff_populate_filespec(one, 0))
		prep_temp_blob(name, temp, one->data, one->size,
static void add_external_diff_name(struct argv_array *argv,
	struct diff_tempfile *temp = prepare_temp_file(name, df);
			      int complete_rewrite,
		add_external_diff_name(&argv, name, one);
			add_external_diff_name(&argv, name, two);
			add_external_diff_name(&argv, other, two);
		return find_unique_abbrev(oid->hash, abbrev);
		if (abbrev > GIT_SHA1_HEXSZ)
			die("BUG: oid abbreviation out of range: %d", abbrev);
	if (one && two && oidcmp(&one->oid, &two->oid)) {
		int abbrev = o->flags.full_index ? 40 : DEFAULT_ABBREV;
			if ((!fill_mmfile(&mf, one) && diff_filespec_is_binary(one)) ||
			    (!fill_mmfile(&mf, two) && diff_filespec_is_binary(two)))
				abbrev = 40;
		struct userdiff_driver *drv = userdiff_find_by_path(attr_path);
		run_external_diff(pgm, name, other, one, two, xfrm_msg,
				  complete_rewrite, o);
static void diff_fill_oid_info(struct diff_filespec *one)
			if (index_path(&one->oid, one->path, &st, 0))
	if (*namep && **namep != '/') {
	if (*otherp && **otherp != '/') {
	diff_fill_oid_info(one);
	diff_fill_oid_info(two);
			     one, null, &msg, o, p);
		builtin_diffstat(p->one->path, NULL, NULL, NULL, diffstat, o, p);
	diff_fill_oid_info(p->one);
	diff_fill_oid_info(p->two);
	builtin_diffstat(name, other, p->one, p->two, diffstat, o, p);
	diff_fill_oid_info(p->one);
	diff_fill_oid_info(p->two);
void diff_setup(struct diff_options *options)
	if (options->setup & DIFF_SETUP_USE_CACHE) {
		if (!active_cache)
			/* read-cache does not die even when it fails
			 * so it is safe for us to do this here.  Also
			 * it does not smudge active_cache or active_nr
			 * when it fails, so we do not have to worry about
			 * cleaning it up ourselves either.
			 */
			read_cache();
	}
	if (40 < options->abbrev)
		options->abbrev = 40; /* full */
}

static int opt_arg(const char *arg, int arg_short, const char *arg_long, int *val)
{
	char c, *eq;
	int len;

	if (*arg != '-')
		return 0;
	c = *++arg;
	if (!c)
		return 0;
	if (c == arg_short) {
		c = *++arg;
		if (!c)
			return 1;
		if (val && isdigit(c)) {
			char *end;
			int n = strtoul(arg, &end, 10);
			if (*end)
				return 0;
			*val = n;
			return 1;
		}
		return 0;
	}
	if (c != '-')
		return 0;
	arg++;
	eq = strchrnul(arg, '=');
	len = eq - arg;
	if (!len || strncmp(arg, arg_long, len))
		return 0;
	if (*eq) {
		int n;
		char *end;
		if (!isdigit(*++eq))
			return 0;
		n = strtoul(eq, &end, 10);
		if (*end)
			return 0;
		*val = n;
	}
	return 1;
}
static int diff_scoreopt_parse(const char *opt);

static inline int short_opt(char opt, const char **argv,
			    const char **optarg)
{
	const char *arg = argv[0];
	if (arg[0] != '-' || arg[1] != opt)
		return 0;
	if (arg[2] != '\0') {
		*optarg = arg + 2;
		return 1;
	}
	if (!argv[1])
		die("Option '%c' requires a value", opt);
	*optarg = argv[1];
	return 2;
static int stat_opt(struct diff_options *options, const char **av)
	const char *arg = av[0];
	char *end;
	int argcount = 1;
	if (!skip_prefix(arg, "--stat", &arg))
		die("BUG: stat option does not begin with --stat: %s", arg);
	end = (char *)arg;
	switch (*arg) {
	case '-':
		if (skip_prefix(arg, "-width", &arg)) {
			if (*arg == '=')
				width = strtoul(arg + 1, &end, 10);
			else if (!*arg && !av[1])
				die_want_option("--stat-width");
			else if (!*arg) {
				width = strtoul(av[1], &end, 10);
				argcount = 2;
			}
		} else if (skip_prefix(arg, "-name-width", &arg)) {
			if (*arg == '=')
				name_width = strtoul(arg + 1, &end, 10);
			else if (!*arg && !av[1])
				die_want_option("--stat-name-width");
			else if (!*arg) {
				name_width = strtoul(av[1], &end, 10);
				argcount = 2;
			}
		} else if (skip_prefix(arg, "-graph-width", &arg)) {
			if (*arg == '=')
				graph_width = strtoul(arg + 1, &end, 10);
			else if (!*arg && !av[1])
				die_want_option("--stat-graph-width");
			else if (!*arg) {
				graph_width = strtoul(av[1], &end, 10);
				argcount = 2;
			}
		} else if (skip_prefix(arg, "-count", &arg)) {
			if (*arg == '=')
				count = strtoul(arg + 1, &end, 10);
			else if (!*arg && !av[1])
				die_want_option("--stat-count");
			else if (!*arg) {
				count = strtoul(av[1], &end, 10);
				argcount = 2;
			}
		break;
	case '=':
		width = strtoul(arg+1, &end, 10);
		if (*end == ',')
			name_width = strtoul(end+1, &end, 10);
		if (*end == ',')
			count = strtoul(end+1, &end, 10);
	}
	/* Important! This checks all the error cases! */
	if (*end)
		return 0;
	return argcount;
static int parse_submodule_opt(struct diff_options *options, const char *value)
{
	if (parse_submodule_params(options, value))
		die(_("Failed to parse --submodule option parameter: '%s'"),
			value);
	return 1;
}

static int parse_diff_filter_opt(const char *optarg, struct diff_options *opt)
			return optarg[i];
static void enable_patch_output(int *fmt) {
static int parse_ws_error_highlight_opt(struct diff_options *opt, const char *arg)
	if (val < 0) {
		error("unknown value after ws-error-highlight=%.*s",
		      -1 - val, arg);
		return 0;
	}
	return 1;
static int parse_objfind_opt(struct diff_options *opt, const char *arg)
		return error("unable to resolve '%s'", arg);
	return 1;
int diff_opt_parse(struct diff_options *options,
		   const char **av, int ac, const char *prefix)
	const char *arg = av[0];
	const char *optarg;
	int argcount;
	if (!prefix)
		prefix = "";
	/* Output format options */
	if (!strcmp(arg, "-p") || !strcmp(arg, "-u") || !strcmp(arg, "--patch")
	    || opt_arg(arg, 'U', "unified", &options->context))
		enable_patch_output(&options->output_format);
	else if (!strcmp(arg, "--raw"))
		options->output_format |= DIFF_FORMAT_RAW;
	else if (!strcmp(arg, "--patch-with-raw")) {
		enable_patch_output(&options->output_format);
		options->output_format |= DIFF_FORMAT_RAW;
	} else if (!strcmp(arg, "--numstat"))
		options->output_format |= DIFF_FORMAT_NUMSTAT;
	else if (!strcmp(arg, "--shortstat"))
		options->output_format |= DIFF_FORMAT_SHORTSTAT;
	else if (skip_prefix(arg, "-X", &arg) ||
		 skip_to_optional_arg(arg, "--dirstat", &arg))
		return parse_dirstat_opt(options, arg);
	else if (!strcmp(arg, "--cumulative"))
		return parse_dirstat_opt(options, "cumulative");
	else if (skip_to_optional_arg(arg, "--dirstat-by-file", &arg)) {
		parse_dirstat_opt(options, "files");
		return parse_dirstat_opt(options, arg);
	}
	else if (!strcmp(arg, "--check"))
		options->output_format |= DIFF_FORMAT_CHECKDIFF;
	else if (!strcmp(arg, "--summary"))
		options->output_format |= DIFF_FORMAT_SUMMARY;
	else if (!strcmp(arg, "--patch-with-stat")) {
		enable_patch_output(&options->output_format);
		options->output_format |= DIFF_FORMAT_DIFFSTAT;
	} else if (!strcmp(arg, "--name-only"))
		options->output_format |= DIFF_FORMAT_NAME;
	else if (!strcmp(arg, "--name-status"))
		options->output_format |= DIFF_FORMAT_NAME_STATUS;
	else if (!strcmp(arg, "-s") || !strcmp(arg, "--no-patch"))
		options->output_format |= DIFF_FORMAT_NO_OUTPUT;
	else if (starts_with(arg, "--stat"))
		/* --stat, --stat-width, --stat-name-width, or --stat-count */
		return stat_opt(options, av);
	else if (!strcmp(arg, "--compact-summary")) {
		 options->flags.stat_with_summary = 1;
		 options->output_format |= DIFF_FORMAT_DIFFSTAT;
	} else if (!strcmp(arg, "--no-compact-summary"))
		 options->flags.stat_with_summary = 0;

	/* renames options */
	else if (starts_with(arg, "-B") ||
		 skip_to_optional_arg(arg, "--break-rewrites", NULL)) {
		if ((options->break_opt = diff_scoreopt_parse(arg)) == -1)
			return error("invalid argument to -B: %s", arg+2);
	}
	else if (starts_with(arg, "-M") ||
		 skip_to_optional_arg(arg, "--find-renames", NULL)) {
		if ((options->rename_score = diff_scoreopt_parse(arg)) == -1)
			return error("invalid argument to -M: %s", arg+2);
		options->detect_rename = DIFF_DETECT_RENAME;
	}
	else if (!strcmp(arg, "-D") || !strcmp(arg, "--irreversible-delete")) {
		options->irreversible_delete = 1;
	}
	else if (starts_with(arg, "-C") ||
		 skip_to_optional_arg(arg, "--find-copies", NULL)) {
		if (options->detect_rename == DIFF_DETECT_COPY)
			options->flags.find_copies_harder = 1;
		if ((options->rename_score = diff_scoreopt_parse(arg)) == -1)
			return error("invalid argument to -C: %s", arg+2);
		options->detect_rename = DIFF_DETECT_COPY;
	else if (!strcmp(arg, "--no-renames"))
		options->detect_rename = 0;
	else if (!strcmp(arg, "--rename-empty"))
		options->flags.rename_empty = 1;
	else if (!strcmp(arg, "--no-rename-empty"))
		options->flags.rename_empty = 0;
	else if (skip_to_optional_arg_default(arg, "--relative", &arg, NULL)) {
		options->flags.relative_name = 1;
		if (arg)
			options->prefix = arg;
	}

	/* xdiff options */
	else if (!strcmp(arg, "--minimal"))
		DIFF_XDL_SET(options, NEED_MINIMAL);
	else if (!strcmp(arg, "--no-minimal"))
		DIFF_XDL_CLR(options, NEED_MINIMAL);
	else if (!strcmp(arg, "-w") || !strcmp(arg, "--ignore-all-space"))
		DIFF_XDL_SET(options, IGNORE_WHITESPACE);
	else if (!strcmp(arg, "-b") || !strcmp(arg, "--ignore-space-change"))
		DIFF_XDL_SET(options, IGNORE_WHITESPACE_CHANGE);
	else if (!strcmp(arg, "--ignore-space-at-eol"))
		DIFF_XDL_SET(options, IGNORE_WHITESPACE_AT_EOL);
	else if (!strcmp(arg, "--ignore-cr-at-eol"))
		DIFF_XDL_SET(options, IGNORE_CR_AT_EOL);
	else if (!strcmp(arg, "--ignore-blank-lines"))
		DIFF_XDL_SET(options, IGNORE_BLANK_LINES);
	else if (!strcmp(arg, "--indent-heuristic"))
		DIFF_XDL_SET(options, INDENT_HEURISTIC);
	else if (!strcmp(arg, "--no-indent-heuristic"))
		DIFF_XDL_CLR(options, INDENT_HEURISTIC);
	else if (!strcmp(arg, "--patience")) {
		int i;
		options->xdl_opts = DIFF_WITH_ALG(options, PATIENCE_DIFF);
		/*
		 * Both --patience and --anchored use PATIENCE_DIFF
		 * internally, so remove any anchors previously
		 * specified.
		 */
		for (i = 0; i < options->anchors_nr; i++)
			free(options->anchors[i]);
		options->anchors_nr = 0;
	} else if (!strcmp(arg, "--histogram"))
		options->xdl_opts = DIFF_WITH_ALG(options, HISTOGRAM_DIFF);
	else if ((argcount = parse_long_opt("diff-algorithm", av, &optarg))) {
		long value = parse_algorithm_value(optarg);
		if (value < 0)
			return error("option diff-algorithm accepts \"myers\", "
				     "\"minimal\", \"patience\" and \"histogram\"");
		/* clear out previous settings */
		DIFF_XDL_CLR(options, NEED_MINIMAL);
		options->xdl_opts &= ~XDF_DIFF_ALGORITHM_MASK;
		options->xdl_opts |= value;
		return argcount;
	} else if (skip_prefix(arg, "--anchored=", &arg)) {
		options->xdl_opts = DIFF_WITH_ALG(options, PATIENCE_DIFF);
		ALLOC_GROW(options->anchors, options->anchors_nr + 1,
			   options->anchors_alloc);
		options->anchors[options->anchors_nr++] = xstrdup(arg);
	}

	/* flags options */
	else if (!strcmp(arg, "--binary")) {
		enable_patch_output(&options->output_format);
		options->flags.binary = 1;
	}
	else if (!strcmp(arg, "--full-index"))
		options->flags.full_index = 1;
	else if (!strcmp(arg, "-a") || !strcmp(arg, "--text"))
		options->flags.text = 1;
	else if (!strcmp(arg, "-R"))
		options->flags.reverse_diff = 1;
	else if (!strcmp(arg, "--find-copies-harder"))
		options->flags.find_copies_harder = 1;
	else if (!strcmp(arg, "--follow"))
		options->flags.follow_renames = 1;
	else if (!strcmp(arg, "--no-follow")) {
		options->flags.follow_renames = 0;
		options->flags.default_follow_renames = 0;
	} else if (skip_to_optional_arg_default(arg, "--color", &arg, "always")) {
		int value = git_config_colorbool(NULL, arg);
		if (value < 0)
			return error("option `color' expects \"always\", \"auto\", or \"never\"");
		options->use_color = value;
	}
	else if (!strcmp(arg, "--no-color"))
		options->use_color = 0;
	else if (!strcmp(arg, "--color-moved")) {
	} else if (!strcmp(arg, "--no-color-moved"))
		options->color_moved = COLOR_MOVED_NO;
	else if (skip_prefix(arg, "--color-moved=", &arg)) {
			die("bad --color-moved argument: %s", arg);
	} else if (skip_to_optional_arg_default(arg, "--color-words", &options->word_regex, NULL)) {
		options->use_color = 1;
		options->word_diff = DIFF_WORDS_COLOR;
	else if (!strcmp(arg, "--word-diff")) {
		if (options->word_diff == DIFF_WORDS_NONE)
			options->word_diff = DIFF_WORDS_PLAIN;
	else if (skip_prefix(arg, "--word-diff=", &arg)) {
			die("bad --word-diff argument: %s", arg);
	}
	else if ((argcount = parse_long_opt("word-diff-regex", av, &optarg))) {
		options->word_regex = optarg;
		return argcount;
	else if (!strcmp(arg, "--exit-code"))
		options->flags.exit_with_status = 1;
	else if (!strcmp(arg, "--quiet"))
		options->flags.quick = 1;
	else if (!strcmp(arg, "--ext-diff"))
		options->flags.allow_external = 1;
	else if (!strcmp(arg, "--no-ext-diff"))
		options->flags.allow_external = 0;
	else if (!strcmp(arg, "--textconv")) {
		options->flags.allow_textconv = 1;
		options->flags.textconv_set_via_cmdline = 1;
	} else if (!strcmp(arg, "--no-textconv"))
		options->flags.allow_textconv = 0;
	else if (skip_to_optional_arg_default(arg, "--ignore-submodules", &arg, "all")) {
		options->flags.override_submodule_config = 1;
		handle_ignore_submodules_arg(options, arg);
	} else if (skip_to_optional_arg_default(arg, "--submodule", &arg, "log"))
		return parse_submodule_opt(options, arg);
	else if (skip_prefix(arg, "--ws-error-highlight=", &arg))
		return parse_ws_error_highlight_opt(options, arg);
	else if (!strcmp(arg, "--ita-invisible-in-index"))
		options->ita_invisible_in_index = 1;
	else if (!strcmp(arg, "--ita-visible-in-index"))
		options->ita_invisible_in_index = 0;

	/* misc options */
	else if (!strcmp(arg, "-z"))
		options->line_termination = 0;
	else if ((argcount = short_opt('l', av, &optarg))) {
		options->rename_limit = strtoul(optarg, NULL, 10);
		return argcount;
	}
	else if ((argcount = short_opt('S', av, &optarg))) {
		options->pickaxe = optarg;
		options->pickaxe_opts |= DIFF_PICKAXE_KIND_S;
		return argcount;
	} else if ((argcount = short_opt('G', av, &optarg))) {
		options->pickaxe = optarg;
		options->pickaxe_opts |= DIFF_PICKAXE_KIND_G;
		return argcount;
	}
	else if (!strcmp(arg, "--pickaxe-all"))
		options->pickaxe_opts |= DIFF_PICKAXE_ALL;
	else if (!strcmp(arg, "--pickaxe-regex"))
		options->pickaxe_opts |= DIFF_PICKAXE_REGEX;
	else if ((argcount = short_opt('O', av, &optarg))) {
		options->orderfile = prefix_filename(prefix, optarg);
		return argcount;
	} else if (skip_prefix(arg, "--find-object=", &arg))
		return parse_objfind_opt(options, arg);
	else if ((argcount = parse_long_opt("diff-filter", av, &optarg))) {
		int offending = parse_diff_filter_opt(optarg, options);
		if (offending)
			die("unknown change class '%c' in --diff-filter=%s",
			    offending, optarg);
		return argcount;
	}
	else if (!strcmp(arg, "--no-abbrev"))
		options->abbrev = 0;
	else if (!strcmp(arg, "--abbrev"))
		options->abbrev = DEFAULT_ABBREV;
	else if (skip_prefix(arg, "--abbrev=", &arg)) {
		options->abbrev = strtoul(arg, NULL, 10);
		if (options->abbrev < MINIMUM_ABBREV)
			options->abbrev = MINIMUM_ABBREV;
		else if (40 < options->abbrev)
			options->abbrev = 40;
	}
	else if ((argcount = parse_long_opt("src-prefix", av, &optarg))) {
		options->a_prefix = optarg;
		return argcount;
	}
	else if ((argcount = parse_long_opt("line-prefix", av, &optarg))) {
		options->line_prefix = optarg;
		options->line_prefix_length = strlen(options->line_prefix);
		graph_setup_line_prefix(options);
		return argcount;
	}
	else if ((argcount = parse_long_opt("dst-prefix", av, &optarg))) {
		options->b_prefix = optarg;
		return argcount;
	}
	else if (!strcmp(arg, "--no-prefix"))
		options->a_prefix = options->b_prefix = "";
	else if (opt_arg(arg, '\0', "inter-hunk-context",
			 &options->interhunkcontext))
		;
	else if (!strcmp(arg, "-W"))
		options->flags.funccontext = 1;
	else if (!strcmp(arg, "--function-context"))
		options->flags.funccontext = 1;
	else if (!strcmp(arg, "--no-function-context"))
		options->flags.funccontext = 0;
	else if ((argcount = parse_long_opt("output", av, &optarg))) {
		char *path = prefix_filename(prefix, optarg);
		options->file = xfopen(path, "w");
		options->close_file = 1;
		if (options->use_color != GIT_COLOR_ALWAYS)
			options->use_color = GIT_COLOR_NEVER;
		free(path);
		return argcount;
	} else
		return 0;
	return 1;
static int diff_scoreopt_parse(const char *opt)
{
	int opt1, opt2, cmd;

	if (*opt++ != '-')
		return -1;
	cmd = *opt++;
	if (cmd == '-') {
		/* convert the long-form arguments into short-form versions */
		if (skip_prefix(opt, "break-rewrites", &opt)) {
			if (*opt == 0 || *opt++ == '=')
				cmd = 'B';
		} else if (skip_prefix(opt, "find-copies", &opt)) {
			if (*opt == 0 || *opt++ == '=')
				cmd = 'C';
		} else if (skip_prefix(opt, "find-renames", &opt)) {
			if (*opt == 0 || *opt++ == '=')
				cmd = 'M';
		}
	}
	if (cmd != 'M' && cmd != 'C' && cmd != 'B')
		return -1; /* that is not a -M, -C, or -B option */

	opt1 = parse_rename_score(&opt);
	if (cmd != 'B')
		opt2 = 0;
	else {
		if (*opt == 0)
			opt2 = 0;
		else if (*opt != '/')
			return -1; /* we expect -B80/99 or -B80 */
		else {
			opt++;
			opt2 = parse_rename_score(&opt);
		}
	}
	if (*opt != 0)
		return -1;
	return opt1 | (opt2 << 16);
}

	if (len == GIT_SHA1_HEXSZ)
	if (abblen < GIT_SHA1_HEXSZ - 3) {
	    !oidcmp(&one->oid, &two->oid) &&
		else if (oidcmp(&p->one->oid, &p->two->oid) ||
	git_SHA_CTX *ctx;
	/* Ignore line numbers when computing the SHA1 of the patch */
	if (starts_with(line, "@@ -"))
		return;

	git_SHA1_Update(data->ctx, line, new_len);
static void patch_id_add_string(git_SHA_CTX *ctx, const char *str)
	git_SHA1_Update(ctx, str, strlen(str));
static void patch_id_add_mode(git_SHA_CTX *ctx, unsigned mode)
	git_SHA1_Update(ctx, buf, len);
/* returns 0 upon success, and writes result into sha1 */
static int diff_get_patch_id(struct diff_options *options, struct object_id *oid, int diff_header_only)
	git_SHA_CTX ctx;
	git_SHA1_Init(&ctx);
		diff_fill_oid_info(p->one);
		diff_fill_oid_info(p->two);
		git_SHA1_Update(&ctx, p->one->path, len1);
		git_SHA1_Update(&ctx, p->two->path, len2);
			git_SHA1_Update(&ctx, p->two->path, len2);
			git_SHA1_Update(&ctx, p->one->path, len1);
			git_SHA1_Update(&ctx, p->one->path, len1);
			git_SHA1_Update(&ctx, p->two->path, len2);
		if (fill_mmfile(&mf1, p->one) < 0 ||
		    fill_mmfile(&mf2, p->two) < 0)
		if (diff_filespec_is_binary(p->one) ||
		    diff_filespec_is_binary(p->two)) {
			git_SHA1_Update(&ctx, oid_to_hex(&p->one->oid),
					GIT_SHA1_HEXSZ);
			git_SHA1_Update(&ctx, oid_to_hex(&p->two->oid),
					GIT_SHA1_HEXSZ);
		if (xdi_diff_outf(&mf1, &mf2, patch_id_consume, &data,
				  &xpp, &xecfg))
	git_SHA1_Final(oid->hash, &ctx);
int diff_flush_patch_id(struct diff_options *options, struct object_id *oid, int diff_header_only)
	int result = diff_get_patch_id(options, oid, diff_header_only);
		die("BUG: WS rules bit mask overlaps with diff symbol flags");
			hashmap_init(&del_lines,
				     (hashmap_cmp_fn)moved_entry_cmp, o, 0);
			hashmap_init(&add_lines,
				     (hashmap_cmp_fn)moved_entry_cmp, o, 0);
			hashmap_free(&add_lines, 0);
			hashmap_free(&del_lines, 0);
	esm.nr = 0;
		memset(&diffstat, 0, sizeof(struct diffstat_t));
		for (i = 0; i < q->nr; i++) {
			struct diff_filepair *p = q->queue[i];
			if (check_pair_status(p))
				diff_flush_stat(p, options, &diffstat);
		}
static int diff_filespec_is_identical(struct diff_filespec *one,
	if (diff_populate_filespec(one, 0))
	if (diff_populate_filespec(two, 0))
static int diff_filespec_check_stat_unmatch(struct diff_filepair *p)
	    diff_populate_filespec(p->one, CHECK_SIZE_ONLY) ||
	    diff_populate_filespec(p->two, CHECK_SIZE_ONLY) ||
	    !diff_filespec_is_identical(p->one, p->two)) /* (2) */
		if (diff_filespec_check_stat_unmatch(p))
void diffcore_fix_diff_index(struct diff_options *options)
			diffcore_break(options->break_opt);
	    !diff_filespec_check_stat_unmatch(p))
static char *run_textconv(const char *pgm, struct diff_filespec *spec,
		size_t *outsize)
	temp = prepare_temp_file(spec->path, spec);
size_t fill_textconv(struct userdiff_driver *driver,
		if (diff_populate_filespec(df, 0))
		die("BUG: fill_textconv called with non-textconv driver");
	*outbuf = run_textconv(driver->textconv, df, &size);
int textconv_object(const char *path,
	textconv = get_textconv(df);
	*buf_size = fill_textconv(textconv, df, buf);