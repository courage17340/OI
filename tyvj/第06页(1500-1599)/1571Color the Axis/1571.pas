{P1571}
type
  rec=record
        l,r:longint;
      end;
var
  a:array[1..4000010] of rec;
  v:array[1..4000010] of boolean;
  n,m,i,j,p,q:longint;
procedure maketree(l,r,x:longint);
var m:longint;
begin
  m:=(l+r) div 2;
  a[x].l:=l;
  a[x].r:=r;
  if l=r then exit;
  if l<=m then maketree(l,m,x*2);
  if m+1<=r then maketree(m+1,r,x*2+1);
end;
procedure work(x,y,k:longint);
var t:longint;
begin
  if (x=a[k].l)and(y=a[k].r) then begin v[k]:=true;exit;end;
  t:=(a[k].l+a[k].r) div 2;
  if x>t then work(x,y,2*k+1);
  if y<=t then work(x,y,2*k);
  if (x<=t)and(y>t) then begin work(x,t,k*2);work(t+1,y,k*2+1);end;
end;
function ans(k:longint):longint;
begin
  if v[k] then exit(0);
  if a[k].l=a[k].r then exit(1);
  exit(ans(2*k)+ans(2*k+1));
end;
begin
  fillchar(v,sizeof(v),false);
  readln(n,m);
  maketree(1,n,1);
  for i:=1 to m do
    begin
      readln(p,q);
      work(p,q,1);
      writeln(ans(1));
    end;
  readln;
end.