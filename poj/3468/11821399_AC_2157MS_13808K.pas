type
  rec=record
        L,r,s,t:int64;
      end;
var
  a:array[1..100000] of longint;
  f:array[1..400000] of rec;
  n,i,j,q,x,y,z:longint;
  ch:char;
procedure build(k,L,r:longint);
var
  m:longint;
begin
  f[k].L:=L;
  f[k].r:=r;
  f[k].t:=0;
  if L=r then
    begin
      f[k].s:=a[r];
      exit;
    end;
  m:=(L+r) shr 1;
  build(k*2,L,m);
  build(k*2+1,m+1,r);
  f[k].s:=int64(f[k*2].s+f[k*2+1].s);
end;
procedure add(k,L,r,x:int64);
var
  m:int64;
begin
  if (L=f[k].L)and(r=f[k].r) then
    begin
      f[k].s:=f[k].s+int64(r-L+1)*x;
      f[k].t:=f[k].t+x;
      exit;
    end;
  if f[k].t<>0 then
    begin
      f[k*2].s:=f[k*2].s+int64(f[k*2].r-f[k*2].L+1)*f[k].t;
      f[k*2].t:=f[k*2].t+f[k].t;
      f[k*2+1].s:=f[k*2+1].s+int64(f[k*2+1].r-f[k*2+1].L+1)*f[k].t;
      f[k*2+1].t:=f[k*2+1].t+f[k].t;
      f[k].t:=0;
    end;
  m:=(f[k].L+f[k].r) shr 1;
  if r<=m then add(k*2,L,r,x);
  if L>m then add(k*2+1,L,r,x);
  if (L<=m)and(m<r) then
    begin
      add(k*2,L,m,x);
      add(k*2+1,m+1,r,x);
    end;
  f[k].s:=f[k*2].s+f[k*2+1].s;
end;
function sum(k,L,r:int64):int64;
var
  m,x:int64;
begin
  if (f[k].L=L)and(f[k].r=r) then exit(f[k].s);
  if f[k].t<>0 then
    begin
      f[k*2].s:=f[k*2].s+int64(f[k*2].r-f[k*2].L+1)*f[k].t;
      f[k*2].t:=f[k*2].t+f[k].t;
      f[k*2+1].s:=f[k*2+1].s+int64(f[k*2+1].r-f[k*2+1].L+1)*f[k].t;
      f[k*2+1].t:=f[k*2+1].t+f[k].t;
      f[k].t:=0;
    end;
  m:=(f[k].L+f[k].r) shr 1;
  if r<=m then exit(sum(k*2,L,r));
  if L>m then exit(sum(k*2+1,L,r));
  exit(sum(k*2,L,m)+sum(k*2+1,m+1,r));
end;
begin
  readln(n,q);
  for i:=1 to n do read(a[i]);
  readln;
  fillchar(f,sizeof(f),0);
  build(1,1,n);
  for i:=1 to q do
    begin
      read(ch);
      if ch='C' then
        begin
          readln(x,y,z);
          add(1,x,y,z);
        end;
      if ch='Q' then
        begin
          readln(x,y);
          writeln(sum(1,x,y));
        end;
    end;
end.