type
  rec=record
        L,r,s:longint;
      end;
var
  a:array[0..15000] of longint;
  f:array[1..130000] of rec;
  n,i,x:longint;
procedure build(k,L,r:longint);
var
  m:longint;
begin
  f[k].L:=L;
  f[k].r:=r;
  f[k].s:=0;
  if L=r then exit;
  m:=(L+r) shr 1;
  build(k*2,L,m);
  build(k*2+1,m+1,r);
end;
procedure add(k,x:longint);
var
  m:longint;
begin
  if f[k].L=f[k].r then
    begin
      inc(f[k].s);
      exit;
    end;
  m:=(f[k].L+f[k].r) shr 1;
  if x<=m then add(k*2,x);
  if x>m then add(k*2+1,x);
  f[k].s:=f[k*2].s+f[k*2+1].s;
end;
function sum(k,L,r:longint):longint;
var
  m:longint;
begin
  if (f[k].L=L)and(f[k].r=r) then exit(f[k].s);
  m:=(f[k].L+f[k].r) shr 1;
  if r<=m then exit(sum(k*2,L,r));
  if L>m then exit(sum(k*2+1,L,r));
  exit(sum(k*2,L,m)+sum(k*2+1,m+1,r));
end;
begin
  readln(n);
  fillchar(f,sizeof(f),0);
  fillchar(a,sizeof(a),0);
  build(1,0,32000);
  for i:=1 to n do
    begin
      readln(x);
      inc(a[sum(1,0,x)]);
      add(1,x);
    end;
  for i:=0 to n-1 do writeln(a[i]);
end.