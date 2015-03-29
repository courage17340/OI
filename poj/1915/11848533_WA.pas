type rec=record x,y,step:longint;end;
var
  a:array[1..8,1..2] of longint=((2,1),(2,-1),(1,2),(1,-2),(-1,2),(-1,-2),(-2,1),(-2,-1));
  b:array[1..90000] of rec;
  v:array[0..300,0..300] of boolean;
  n,i,j,m,x,y,x1,y1,k,L,p:longint;
begin
  readln(n);
  for k:=1 to n do
    begin
      readln(L);
      readln(x,y);
      readln(x1,y1);
      if (x=y)and(x1=y1) then
        begin
          writeln(0);
          continue;
        end;
      b[1].step:=0;
      b[1].x:=x;
      b[1].y:=y;
      i:=1;
      j:=1;
      fillchar(v,sizeof(v),false);
      v[x,y]:=true;
      while i<j+1 do
        begin
          if (b[i].x=x1)and(b[i].y=y1) then
            begin
              writeln(b[i].step);
              break;
            end;
          for p:=1 to 8 do
            if (0<=b[i].x+a[p,1])and(b[i].x+a[p,1]<L)and(0<=b[i].y+a[p,2])and(b[i].y+a[p,2]<L) then
              if not v[b[i].x+a[p,1],b[i].y+a[p,2]] then
                begin
                  v[b[i].x+a[p,1],b[i].y+a[p,2]]:=true;
                  inc(j);
                  b[j].x:=b[i].x+a[p,1];
                  b[j].y:=b[i].y+a[p,2];
                  b[j].step:=b[i].step+1;
                end;
          inc(i);
        end;
    end;
end.