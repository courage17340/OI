type rec=record x,step:longint;end;
var
  v:array[1..140000] of boolean;
  b:array[1..140000] of rec;
  n,i,j,k:longint;
procedure print(x:longint);
begin
  writeln(x);
  halt;
end;
begin
  readln(n,k);
  fillchar(v,sizeof(v),false);
  i:=1;
  j:=1;
  if n>=k then print(n-k);
  v[n]:=true;
  b[1].x:=n;
  b[1].step:=0;
  while i<j+1 do
    begin
      if (b[i].x+1<=k)and(not v[b[i].x+1]) then
        begin
          v[b[i].x+1]:=true;
          inc(j);
          b[j].step:=b[i].step+1;
          b[j].x:=b[i].x+1;
          if b[j].x=k then print(b[j].step);
        end;
      if (b[i].x-1>=0)and(not v[b[i].x-1]) then
        begin
          v[b[i].x-1]:=true;
          inc(j);
          b[j].step:=b[i].step+1;
          b[j].x:=b[i].x-1;
          if b[j].x=k then print(b[j].step);
        end;
      if (b[i].x<k)and(b[i].x*2<140000)and(not v[b[i].x*2]) then
        begin
          v[b[i].x*2]:=true;
          inc(j);
          b[j].step:=b[i].step+1;
          b[j].x:=b[i].x*2;
          if b[j].x=k then print(b[j].step);
        end;
      inc(i);
    end;
end.