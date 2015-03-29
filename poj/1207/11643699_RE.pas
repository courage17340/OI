{1207}
type
  rec=record
        L,r,max:longint;
      end;
const maxn=10000;
var
  a:array[1..maxn] of longint;
  b:array[1..40000] of rec;
  i,j,p,q:longint;
function work(x:longint):longint;
begin
  if x=1 then exit(1);
  if x<=maxn then if a[x]>0 then exit(a[x]);
  if x mod 2=0 then exit(work(x div 2)+1);
  exit(work(3*x+1)+1);
end;

function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;

procedure build(p,m,n:longint);
var
  mid:longint;
begin
  b[p].L:=m;
  b[p].r:=n;
  if m=n then
    begin
      b[p].max:=a[m];
      exit;
    end;
  mid:=(m+n) shr 1;
  build(p*2,m,mid);
  build(p*2+1,mid+1,n);
  b[p].max:=max(b[p*2].max,b[p*2+1].max);
end;

function find(k,m,n:longint):longint;
var
  mid:longint;
begin
  if (m=b[k].L)and(n=b[k].r) then exit(b[k].max);
  mid:=(b[k].L+b[k].r) shr 1;
  if n<=mid then exit(find(k*2,m,n));
  if m>mid then exit(find(k*2+1,m,n));
  exit(max(find(k*2,m,mid),find(k*2+1,mid+1,n)));
end;

begin
  fillchar(a,sizeof(a),0);
  for i:=1 to maxn do a[i]:=work(i);
  build(1,1,maxn);
  while not eof do
    begin
      readln(p,q);
      writeln(p,' ',q,' ',find(1,p,q));
    end;
end.