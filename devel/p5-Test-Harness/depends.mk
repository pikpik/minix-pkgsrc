# $NetBSD$

# perl58>=5.8.3 includes Test::Harness, so allow it to satisfy this
# dependency.
DEPENDS+=	{p5-Test-Harness-[0-9]*,perl{,-thread}>=5.8.3}:../../devel/p5-Test-Harness
