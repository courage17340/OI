const maxn=100000;
var a,c : array [0..maxn] of longint;
    i,now,n : longint;
    ans : int64;
begin
  read(n);
  for i := 1 to n do read(c[i],a[i]);
  now := -maxlongint;ans := 0;
  for i := n downto 1 do
  if a[i]>now then begin now := a[i];inc(ans,a[i]*c[i]);end
              else inc(ans,now*c[i]);
  writeln(ans);
end.