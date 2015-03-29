type rec=record x,y:longint;end;
var
  f,d:array[0..50000] of longint;
  a:array[1..100000] of rec;
  yes:array[1..50000] of boolean;
  n,i,j,m,k,ans:longint;
procedure sort(m,n:longint);
var
  i,j,p:longint;
  t:rec;
begin
  p:=a[(m+n) shr 1].x;
  i:=m;j:=n;
  repeat
    while a[i].x<p do inc(i);
    while a[j].x>p do dec(j);
    if i<=j then
      begin
        t:=a[i];
        a[i]:=a[j];
        a[j]:=t;
        inc(i);
        dec(j);
      end;
  until i>j;
  if m<j then sort(m,j);
  if i<n then sort(i,n);
end;
function search(p:longint):longint;
var i,j,q:longint;
begin
  if f[p]>0 then exit(f[p]);
  j:=d[p];
  search:=0;
  if (j>0)and(d[p+1]>0) then for i:=j to d[p+1]-1 do
    search:=search+search(a[i].y) mod 11129;
  if search=0 then search:=1;
  search:=search mod 11129;
  f[p]:=search;
end;
begin
  read(n,m);fillchar(yes,sizeof(yes),false);
  for i:=1 to n do begin a[i].y:=i;a[i].x:=0;end;
  for i:=1 to m do begin read(a[i].y,a[i].x);yes[a[i].y]:=true;end;
  sort(1,m);
  fillchar(d,sizeof(d),0);
  fillchar(f,sizeof(f),0);
  for i:=1 to m do
    if d[a[i].x]=0 then d[a[i].x]:=i;
  d[n+1]:=m+1;
  for i:=1 to n do f[i]:=search(i);
  ans:=0;for i:=1 to n do if not yes[i] then inc(ans,f[i]);
  writeln(ans mod 11129);
  readln;readln;
end.
