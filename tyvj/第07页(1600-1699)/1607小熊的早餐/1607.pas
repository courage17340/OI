var
  a:array[0..400000] of longint;{堆}
  b:array[0..100000] of longint;{指针1}
  c:array[0..400000] of longint;{指针2}
  n,i,j,k,m,q:longint;
  s:string;
procedure exchange(x,y:longint);
var
  t:longint;
begin
  t:=c[x];c[x]:=c[y];c[y]:=t;
  t:=a[x];a[x]:=a[y];a[y]:=t;
  b[c[x]]:=x;b[c[y]]:=y;
end;
procedure work(x,kind:longint);
begin
  if kind=1 then
    begin
      if x>=200000 then exit;
      if (a[x]>=a[2*x])and(a[x]>=a[2*x+1]) then exit;
      if a[2*x]>=a[2*x+1]
        then begin exchange(x,2*x);work(2*x,1);end
        else begin exchange(x,2*x+1);work(2*x+1,1);end;
    end;
  if kind=2 then
    begin
      if x=1 then exit;
      if a[x]<=a[x div 2] then exit;
      exchange(x,x div 2);
      work(x div 2,2);
    end;
end;
begin
  readln(n,m);
  for i:=1 to n do c[i]:=i;
  for i:=1 to n do b[i]:=i;
  fillchar(a,sizeof(a),0);
  for i:=1 to m do
    begin
      readln(s);
      case s[1] of
        'Y':writeln(a[1]);
        'L':begin
              delete(s,1,5);
              val(copy(s,1,pos(' ',s)-1),j,q);
              delete(s,1,pos(' ',s));
              val(s,k,q);
              q:=a[b[j]];
              a[b[j]]:=k;
              if q>k then work(b[j],1);{下沉}
              if q<k then work(b[j],2);{上浮}
            end;
        'U':begin
              delete(s,1,7);
              val(s,j,q);
              a[b[j]]:=-1;
              work(b[j],1);
            end;
      end;
    end;
  readln;
end.